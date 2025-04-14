import base64

base64_string = "c3ludHtDQUVTQVJfTUUhLWwwaF9UMDdfdkdfZTF0dUchfQo="

decoded_bytes = base64.b64decode(base64_string)
decoded_text = decoded_bytes.decode('utf-8')

print(decoded_text)
