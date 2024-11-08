import os
import io
import sys
import pip
import time
import stat
import shutil
import tarfile
import datetime
import subprocess
import requests
from requests.exceptions import RequestException
from selenium.common.exceptions import WebDriverException
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.firefox.service import Service as FirefoxService
from selenium.webdriver.chrome.options import Options as ChromeOptions
from selenium.webdriver.firefox.options import Options as FirefoxOptions
from webdriver_manager.chrome import ChromeDriverManager
from webdriver_manager.firefox import GeckoDriverManager
from bs4 import BeautifulSoup, Tag

REQUIRED_LIBS: list[str] = ["bs4", "selenium", "requests", "webdriver_manager"]
RED_COLOR: str = "rgb(248 113 113)" 
ORANGE_COLOR: str = "rgb(251 146 60)"
YELLOW_COLOR: str = "rgb(250 204 21)"
LIME_COLOR: str = "rgb(163 230 53)"
GREEN_COLOR: str = "rgb(74 222 128)"  # 100 Score

def onerror(func, path: str, _) -> None:
    if not os.access(path, os.W_OK):
        # Change file permission
        os.chmod(path, stat.S_IWUSR)
        func(path)
    else:
        # If error is not due to permission issues, raise
        raise Exception("Could not delete cloned directory.")

def get_webdriver(browser: str = "chrome"):
    """
    Get WebDriver based on selected browser
    
    :param browser: 'chrome' or 'firefox'
    :return: Configured WebDriver and options
    """
    try:
        if browser == "chrome":
            options = ChromeOptions()
            options.add_argument('--headless')
            options.add_argument('--no-sandbox')
            options.add_argument('--disable-dev-shm-usage')
            options.add_argument('--disable-gpu')
            options.add_argument('--window-size=1920,1080')
            options.add_argument('--disable-extensions')
            options.add_argument('--proxy-server="direct://"')
            options.add_argument('--proxy-bypass-list=*')
            options.add_argument('--start-maximized')
            
            # More robust driver management
            service = ChromeService(ChromeDriverManager().install())
            driver = webdriver.Chrome(service=service, options=options)
        
        else:  # Default to Firefox
            options = FirefoxOptions()
            options.add_argument('--headless')
            options.add_argument('--no-sandbox')
            options.add_argument('--disable-dev-shm-usage')
            options.add_argument('--disable-gpu')
            options.add_argument('--window-size=1920,1080')
            options.add_argument('--disable-extensions')
            options.add_argument('--proxy-server="direct://"')
            options.add_argument('--proxy-bypass-list=*')
            options.add_argument('--start-maximized')
            
            # More robust driver management
            service = FirefoxService(GeckoDriverManager().install())
            driver = webdriver.Firefox(service=service, options=options)
        
        # Enhanced timeout settings
        driver.set_page_load_timeout(300)  # 5 minutes timeout
        driver.implicitly_wait(10)  # Wait up to 10 seconds for elements
        
        return driver
    
    except Exception as e:
        print(f"Error setting up WebDriver: {e}")
        raise

def getScoreColor(value: int) -> str:
    if value in range(0, 24):
        return RED_COLOR
    elif value in range(25, 49):
        return ORANGE_COLOR
    elif value in range(50, 74):
        return YELLOW_COLOR
    elif value in range(75, 100):
        return LIME_COLOR
    elif value == 100:
        return GREEN_COLOR   

def updateReadme(name: str, value: int) -> None:
    URL: str = f"https://training.olinfo.it/task/{name}"
    string: str = f" - [📁](./src/{name}/) **[{name}]({URL})** <span style=\"white-space: pre; border-radius:.5rem; background-color:{getScoreColor(value)}; color:black\">  {value}  </span>\n"
    
    with open("./README.md", "r", encoding="utf-8") as f:
        lines: list[str] = f.readlines()

    found: bool = False
    for i, line in enumerate(lines):
        if f"[{name}]" in line:
            lines[i] = string
            found = True
            break

    if not found:
        lines.append(string)

    with open("./README.md", "w", encoding="utf-8") as f:
        f.writelines(lines)

def download(url: str, browser: str = "chrome") -> None:
    NAME: str = url.split('/')[-1]
    DIR_NAME: str = f"./OIS/{NAME}"

    # Ensure src directory exists
    os.makedirs("./OIS", exist_ok=True)

    if (os.path.exists(DIR_NAME)):
        raise Exception("Project directory already exists")

    # Create and start working in project dir
    os.makedirs(DIR_NAME, exist_ok=True)
    os.chdir(DIR_NAME)

    max_retries = 3
    driver = None
    try:
        driver = get_webdriver(browser)
        
        # Get attachments page
        driver.get(f"{url}/attachments")
        time.sleep(3)  # Increased wait time
        ATTACHMENTS_HTML_DATA: str = driver.page_source
        
        # Get PDF instructions
        driver.get(url)
        time.sleep(3)  # Increased wait time
        HTML_DATA: str = driver.page_source

        # Get all download href in the page
        soupAttachments = BeautifulSoup(ATTACHMENTS_HTML_DATA, "html.parser")
        anchors: list[Tag] = [anchor for anchor in soupAttachments.find_all('a') if 'download' in anchor.attrs]

        # Download all attachments with retry mechanism
        for anchor in anchors:
            ANCHOR_URL: str = anchor.get('href')
            for attempt in range(max_retries):
                try:
                    response = requests.get(ANCHOR_URL, timeout=30)
                    response.raise_for_status()
                    
                    with open(ANCHOR_URL.split('/')[-1], 'wb') as f:
                        f.write(response.content)
                    break
                except RequestException as e:
                    if attempt == max_retries - 1:
                        print(f"Error downloading attachment: {str(e)}")
                        raise
                    time.sleep(5)

        # If there are no source file create template
        if len([file for file in os.listdir(".") if file.endswith(".cpp")]) == 0:
            with open(f"{NAME}.cpp", 'w', encoding="utf-8") as f, open("../../template.cpp", 'r', encoding="utf-8") as template:
                f.write(f"// {url}\n\n")
                f.write(template.read())

        # Get PDF link with retry mechanism
        soupMain = BeautifulSoup(HTML_DATA, "html.parser")
        objects: list[Tag] = [object for object in soupMain.find_all('object') if 'data' in object.attrs and "testo.pdf" in object.get('data')]
        for object in objects:
            PDF_URL: str = object.get('data')
            for attempt in range(max_retries):
                try:
                    response = requests.get(PDF_URL, timeout=30)
                    response.raise_for_status()
                    
                    with open("testo.pdf", 'wb') as f:
                        f.write(response.content)
                    break
                except RequestException as e:
                    if attempt == max_retries - 1:
                        print(f"Error downloading PDF: {str(e)}")
                        raise
                    time.sleep(5)

    except Exception as e:
        print(f"Error in download process: {e}")
        raise
    finally:
        if driver:
            driver.quit()

    os.chdir("../../")
    # Add readme entry
    updateReadme(NAME, 0)

def remove(name: str) -> None:
    # Remove directory
    shutil.rmtree(f"./OIS/{name}")

    # Update Readme
    with open("./README.md", "r", encoding="utf-8") as f:
        lines: list[str] = f.readlines()

    for i, line in enumerate(lines):
        if f"[{name}]" in line:
            lines.pop(i)
            break

    with open("./README.md", "w", encoding="utf-8") as f:
        f.writelines(lines)

if __name__ == "__main__":
    # Install required libraries
    for lib in REQUIRED_LIBS:
        try:
            __import__(lib)
        except ImportError:
            pip.main(["install", lib])

    ARGS: list[str] = sys.argv[1:]

    if len(ARGS) == 0:
        print("manager.py flags:\n"
              "\t--add <link> [browser]\n"
              "\t--remove <name>\n"
              "\t--set <name> <score>\n"
              "Browsers: chrome (default), firefox\n"
              )

    i: int = 0
    while i < len(ARGS):
        match (ARGS[i]):
            case "--add":
                browser = "chrome" if len(ARGS) <= i+2 else ARGS[i+2]
                download(ARGS[i+1], browser)
                i+=3 if len(ARGS) > i+2 else 2
            case "--remove":
                remove(ARGS[i+1])
                i+=2
            case "--set":
                updateReadme(ARGS[i+1], int(ARGS[i+2]))
                i+=3