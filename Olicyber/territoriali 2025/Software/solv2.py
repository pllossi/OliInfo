import ctypes
from pwn import *

exe = ELF("magicbb")
libc = exe.libc

final = bytes.fromhex("1f84e6290b29a50954607fb2ad6615796a522d688d89acffe95a771ce9ba0d12b0288d7c")
libc = ctypes.CDLL(None)
libc.rand.restype = ctypes.c_int
libc.srand(0x1337)

raw_output = [b""]*36
raw_inputs = final

rands = []
for i in range(500):
    rands.append(libc.rand())

def xor(j):
    r = rands[j] & 0xff
    for i in range(36):
        raw_output[i] = raw_inputs[i] ^ r

def add(j):
    r = rands[j] & 0xff
    for i in range(36):
        raw_output[i] = (raw_inputs[i] + r) & 0xff

def sub(j):
    r = rands[j] & 0xff
    for i in range(36):
        raw_output[i] = (raw_inputs[i]+0x100 - r) & 0xff

def rotl(j):
    r = 36 * (rands[j] // 0x24)
    for i in range(36):
        raw_output[i] = raw_inputs[(i + (rands[j] % 0x24)) % 0x24]

def rotr(j):
    r = 36 * (rands[j] // 0x24)
    for i in range(36):
        raw_output[i] = raw_inputs[(i - (rands[j] % 0x24) + 36) % 0x24]

for i in range(499, -1, -1):
    op = i%5
    if op == 0:
        xor(i)
        raw_inputs = bytes(raw_output)
    elif op == 1:
        sub(i)
        raw_inputs = bytes(raw_output)
    elif op == 2:
        add(i)
        raw_inputs = bytes(raw_output)
    elif op == 3:
        rotr(i)
        raw_inputs = bytes(raw_output)
    elif op == 4:
        rotl(i)
        raw_inputs = bytes(raw_output)

print(raw_inputs.hex())
