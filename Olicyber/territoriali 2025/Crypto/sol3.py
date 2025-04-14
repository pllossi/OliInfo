from pwn import process, remote

USERNAME = "aaaa;index0=0;index1=1;index2=2;index3=3;xx=yy" + "\x09" * 9 

#r = process(["python3", "secure_passphrase_generator.py"])
r = remote("spg.challs.territoriali.olicyber.it", 38002)

r.sendlineafter(b"> ", b"1")
r.sendlineafter(b"Username? ", b"aaaa")
r.sendlineafter(b"> ", b"1")
r.sendlineafter(b"Username? ", USERNAME.encode())
token = bytes.fromhex(r.recvline_contains(b"Nel caso la dimenticassi, puoi recuperarla con il seguente token: ").decode().split('token: ')[-1])
token = token[:64+16]
print(token.hex())
r.interactive()
