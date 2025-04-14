from pwn import *
from Crypto.PublicKey.ECC import EccPoint
from Crypto.PublicKey import ECC
import json

# Helper class for the ciphertext
class Ciphertext:
    def __init__(self, R, S):
        self.R = R
        self.S = S
    
    @classmethod
    def from_pt(cls, m, k=None):
        # Implement encryption here
        # This should create R = kG and S = kH + mG
        # where k is random if not provided
        if k is None:
            k = random.randint(1, curve.order)
        R = k * G
        S = k * H + m * G
        return cls(R, S)

# Connect to server
conn = remote('offtopic.challs.olicyber.it', 38030)

# Setup curve parameters
curve = ECC.construct(curve='P-256').curve
G = curve.G

# First send a public key (using 2G as H)
H = 2 * G  # We know discrete log is 2
conn.sendline(json.dumps({"Hx": int(H.x), "Hy": int(H.y)}).encode())

# For each round:
for _ in range(128):
    # Send encrypted bit (0 or 1)
    bit = random.choice([0, 1])
    C = Ciphertext.from_pt(bit)
    data = {"Rx": int(C.R.x), "Ry": int(C.R.y), 
            "Sx": int(C.S.x), "Sy": int(C.S.y)}
    conn.sendline(json.dumps(data).encode())
    
    # Receive response and decrypt
    resp = json.loads(conn.recvline())
    
    # Convert response points to EccPoints
    R1 = EccPoint(resp["R1x"], resp["R1y"], curve)
    S1 = EccPoint(resp["S1x"], resp["S1y"], curve)
    R2 = EccPoint(resp["R2x"], resp["R2y"], curve)
    S2 = EccPoint(resp["S2x"], resp["S2y"], curve)
    
    # Decrypt ciphertexts using our knowledge of H = 2G
    # S - 2R should equal mG
    m0 = (S1 - 2*R1) == G
    m1 = (S2 - 2*R2) == G
    
    # Send recovered messages
    conn.sendline(json.dumps({"m0": int(m0), "m1": int(m1)}).encode())

# Get flag
print(conn.recvline().decode())
