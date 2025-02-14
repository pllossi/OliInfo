from pwn import *
import re
import time

# Connessione al server
io = remote("software-18.challs.olicyber.it", 13001)

# Aspettiamo l'inizio della challenge
io.recvuntil(b"... Invia un qualsiasi carattere per iniziare ...")
io.sendline(b"")  # Invia un carattere per iniziare

start_time = time.time()

for i in range(100):  # 100 step in 10 secondi
    line = io.recvline().decode().strip()  # Riceviamo la linea con il numero
    print(f"[Step {i+1}] Ricevuto: {line}")

    # Estrai il numero esadecimale
    match = re.search(r"0x[0-9a-fA-F]+", line)
    is_32bit = "32-bit" in line  # Controlliamo se il numero è a 32-bit

    if match:
        numero = int(match.group(0), 16)
    else:
        print("Errore: numero non trovato")
        break
    
    # Impacchettiamo il numero in base alla dimensione
    if is_32bit:
        packed_num = p32(numero, endian='little')  # 4 BYTE
    else:
        packed_num = p64(numero, endian='little')  # 8 BYTE

    print(f"Rispondendo con: {packed_num.hex()}")  # Debug in esadecimale
    io.send(packed_num)  # Invio binario

# Stampiamo l'output finale
print(io.recvall(timeout=2).decode())

end_time = time.time()
print(f"Tempo totale: {end_time - start_time:.2f} secondi")
