import os
import re
import sys
import pip
import time
import base64
import shutil

TRAINING_TOKEN: str
with open("bin/training_token", 'r') as f:
        TRAINING_TOKEN = f.read()

def getScoreColor(value: int) -> str:
        if value in range(0, 24):
                return "rgb(248 113 113)"
        elif value in range(25, 49):
                return "rgb(251 146 60)"
        elif value in range(50, 69):
                return "rgb(250 204 21)"
        elif value in range(75, 99):
                return "rgb(163 230 53)"
        elif value == 100:
                return "rgb(74 222 128)"   

def findInReadme(name: str) -> tuple[str, int] | None:
        with open("./README.md", "r", encoding="utf-8") as f:
                lines: list[str] = f.readlines()
        
        for i, line in enumerate(lines):
                if f"[{name}]" in line:
                        return [line, i]

        return None

def updateReadme(name: str, value: int) -> None:
        URL: str = f"https://training.olinfo.it/task/{name}"
        string: str = f" - [📁](./OIS/{name}/) **[{name}]({URL})** <span style=\"white-space: pre; border-radius:.5rem; background-color:{getScoreColor(value)}; color:black\">  {value}  </span>\n"
        
        with open("./README.md", "r", encoding="utf-8") as f:
                lines: list[str] = f.readlines()

        position: tuple[str, int] | None = findInReadme(name)

        # If name is already in README update it, if not add it
        if position:
                lines[position[1]] = string
        else:
                lines.append(string)

        with open("./README.md", "w", encoding="utf-8") as f:
                f.writelines(lines)

def download(name: str) -> None:
        # Create and move to project dir
        DIR_NAME: str = f"./OIS/{name}"
        os.mkdir(DIR_NAME)
        os.chdir(DIR_NAME)

        # Get task info from API
        response: Response = requests.post("https://training.olinfo.it/api/task", json={
                "action": "get", 
                "name": name
        })
        response.raise_for_status()

        # Get "attachments" and "statements" from response
        json: dict = response.json()
        attachments: list[list[str]] = json.get("attachments", [])
        statements: dict[str, str] = json.get("statements", [])

        # Download PDF instructions
        instructions: tuple[str, str] = next(iter(statements.items()))
        response = requests.get(f"https://training.olinfo.it/api/files/{instructions[1]}/{instructions[0]}")
        response.raise_for_status()
        with open("testo.pdf", 'wb') as f:
                f.write(response.content)

        # Download all attachments
        for attachment in attachments:
                # Fetch attachment
                response: Response = requests.get(f"https://training.olinfo.it/api/files/{attachment[1]}/{attachment[0]}")
                response.raise_for_status()

                # Write attachment to file
                with open(attachment[0], 'wb') as f:
                        f.write(response.content)

        # If there are no source file create template
        if len([file for file in os.listdir(".") if file.endswith(".cpp")]) == 0:
                with open(f"{name}.cpp", 'w', encoding="utf-8") as f, open("../../bin/template.cpp", 'r', encoding="utf-8") as template:
                        f.write(f"// https://training.olinfo.it/task/{name}\n\n")
                        f.write(template.read())

        os.chdir("../../")
        with open("./README.md", 'a', encoding="utf-8") as f:
                # Add readme entry
                updateReadme(name, 0)

def remove(name: str) -> None:
        # Remove directory
        shutil.rmtree(f"./OIS/{name}")

        # Update Readme
        with open("./README.md", "r", encoding="utf-8") as f:
                lines: list[str] = f.readlines()

        # Remove line containing the name
        lines.remove(lines[[i for i, line in enumerate(lines) if f"[{name}]" in line][0]])
        with open("./README.md", "w", encoding="utf-8") as f:
                f.writelines(lines)

def send(name: str, fileName: str) -> None:
        DIR_NAME: str = f"./OIS/{name}"
        ENCRYPTED_FILE_CONTENT: str

        with open(f"{DIR_NAME}/{fileName}", "rb") as f:
                ENCRYPTED_FILE_CONTENT = base64.b64encode(f.read()).decode("utf-8")

        # Get task info from API
        response: Response = requests.post("https://training.olinfo.it/api/task", json={
                "action": "get", 
                "name": name
        })
        response.raise_for_status()

        # Get "submission_format" from response
        json: dict = response.json()
        submission_format: list[str] = json.get("submission_format", [])

        # Send problem
        response = requests.post("https://training.olinfo.it/api/submission", json={
                "action": "new", 
                "files": {
                        submission_format[-1]: {
                                "data": ENCRYPTED_FILE_CONTENT,
                                "filename": "source.txt",
                                "language": "C++17 / g++"
                        }
                }, 
                "task_name": name
        }, cookies={
                "training_token": TRAINING_TOKEN
        })
        response.raise_for_status()
        
        # Get "id" from response
        json = response.json()
        id: int = json.get("id")
        assert id, f"Error generating submission, json: {json}"

        print(f"[DEBUG]  Submission ID: {id}\n")

        # Wait for compilation and evaluation
        score: int | float | None = None
        while score is None:
                response = requests.post("https://training.olinfo.it/api/submission", json={
                        "action": "details",
                        "id": str(id)
                }, cookies={
                        "training_token": TRAINING_TOKEN
                })
                response.raise_for_status()

                # Check if score has been set
                json = response.json()
                score = json.get("score")

                # Wait before sending request again
                time.sleep(2)

        # Force decimal removal
        score = int(score)

        # Print score in console.
        print(f"Score: {score}.")
        if json.get("compilation_outcome") != "ok":
                print("Compilation Error!")
                print('\t', str(json.get("compilation_stderr")).replace('\n', "\n\t"), '\n')

        # Get entry in README
        position: tuple[str, int] | None = findInReadme(ARGS[i+1])
        assert position, "Problem not in README.md"

        # Set score to the highest score, the present one or the previous one.
        score = max(score, int(re.search(r"  ([0-9]+)  ", position[0]).group(1)))
        with open("./README.md", 'a', encoding="utf-8") as f:
                # Add readme entry
                updateReadme(ARGS[i+1], score)

if __name__ == "__main__":
        # Download all required libraries
        for lib in [ "requests" ]:
                try:
                        __import__(lib)
                except ImportError:
                        pip.main(["install", lib])

        import requests
        from requests import Response

        ARGS: list[str] = sys.argv[1:]

        if len(ARGS) == 0:
                print("manager.py flags:\n\t--add <name>\n\t--remove <name>\n\t--send <name> <file-name>\n\t--set <name> <score>\n")

        i: int = 0
        while i < len(ARGS):
                match (ARGS[i]):
                        case "--add":
                                download(ARGS[i+1])
                                i+=2
                        case "--remove":
                                remove(ARGS[i+1])
                                i+=2
                        case "--send":
                                send(ARGS[i+1], ARGS[i+2])
                                i+=3
                        case "--set":
                                updateReadme(ARGS[i+1], int(ARGS[i+2]))
                                i+=3
                        case _:
                                i+=1
                        