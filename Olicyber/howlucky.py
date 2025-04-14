from pwn import *
x = 1804289383 
r = remote("lucky.challs.olicyber.it", 17000)
r.recv()
r.sendline(str(x).encode())
r.recvuntil(b"ptm")
print("ptm" + r.recv().decode())