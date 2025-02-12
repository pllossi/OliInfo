import random

def encrypt_flag(flag):
    for key in range(256):  # Try all possible keys
        random.seed(key)
        test = "flag{"  # Known start
        result = ""
        
        # Test if this key produces something starting with "flag{"
        for c in test:
            encrypted_char = ord(c) ^ random.randint(0, 255)
            result += hex(encrypted_char)[2:].zfill(2)
        
        # If we found a matching start, this is likely the right key
        if flag.startswith(result):
            # Decrypt the whole flag with this key
            random.seed(key)
            plaintext = []
            for i in range(0, len(flag), 2):
                c = int(flag[i:i+2], 16)
                decrypted_char = c ^ random.randint(0, 255)
                plaintext.append(chr(decrypted_char))
            return ''.join(plaintext)
    
    return "Key not found"

flag = input().strip()

encrypted_flag = encrypt_flag(flag)

print(encrypted_flag)


