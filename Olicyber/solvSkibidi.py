from pwn import *

# Create operation lookup dictionary to avoid multiple if-elif statements
OPERATIONS = {
    b'DIFFERENZA': lambda a, b: a - b,
    b'DIVISIONE_INTERA': lambda a, b: a // b,
    b'POTENZA': lambda a, b: a ** b,
    b'PRODOTTO': lambda a, b: a * b,
    b'SOMMA': lambda a, b: a + b
}

def solve_one(r):
    op = r.recvuntil(b' ', drop=True)
    a = int(r.recvuntil(b' ', drop=True).decode())
    b = int(r.recvuntil(b' ', drop=True).decode())
    
    try:
        res = OPERATIONS[op](a, b)
        r.sendline(str(res).encode())
    except KeyError:
        print('Unknown operation:', op)
        sys.exit(1)

r = remote('2048.challs.olicyber.it', 10007)
r.recvlines(2)

for _ in range(2048):
    solve_one(r)

r.interactive()
