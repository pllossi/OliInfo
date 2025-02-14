import requests

url = "http://web-09.challs.olicyber.it/login"

data = {
    "username": "admin",
    "password": "admin"
}

headers = {
    "Content-Type": "application/json"
}

response = requests.post(url, json=data, headers=headers)

print("Status Code:", response.status_code)
print("Response Text:", response.text)
