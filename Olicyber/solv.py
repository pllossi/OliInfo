def xor(a, b):
    return bytes([x ^ y for x,y in zip(a,b)])

encrypted = bytes.fromhex("27893459dc8772d66261ff8633ba1e5097c10fba257293872fd2664690e975d2015fc4fd3c")
known_start = b"flag{"
key = xor(encrypted[:6], known_start)
decrypted = xor(encrypted, key * (len(encrypted)//len(key) + 1))

# Stampiamo byte per byte
for i, b in enumerate(decrypted):
    print(f"Position {i}: {hex(b)} (ASCII: {chr(b) if 32 <= b <= 126 else '?'})")