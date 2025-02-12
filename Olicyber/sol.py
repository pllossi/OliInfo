import pwn

r = pwn.remote('software-17.challs.olicyber.it', 13000)

r.sendline()
try:
    for i in range(0,10):
        data = r.recv().decode()
        if 'flag{' in data:
            print(data)
            break
            
        r.recvuntil(b'somma questi numeri')
        r.recvline()
        num = r.recvline().decode()
        
        num = num.split(',')
        num[0] = num[0].replace('[','')
        num[-1] = num[-1].replace(']','')
        
        total = sum(int(n) for n in num)
        r.sendline(str(total).encode())
    r.interactive()

except EOFError:
    print("Connection closed")
except Exception as e:
    print(f"Error: {e}")
finally:
    r.close()
