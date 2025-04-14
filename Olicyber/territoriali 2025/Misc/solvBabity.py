#!/usr/bin/env python3

import os

hex_expected_output = "1f84e6290b29a50954607fb2ad6615796a522d688d89acffe95a771ce9ba0d12b0288d7c"
raw_expected_output = list(bytes.fromhex(hex_expected_output))

with open('nums.txt', "r") as f:                    # C rand() numbers sequence
   nums = [int(x) for x in f.read().split(", ")]

rand_used = 0
def rand():
   global rand_used
   rand_used -= 1
   return nums[rand_used]

HEX_LEN = len(hex_expected_output)
RAW_LEN = HEX_LEN // 2

raw_input = raw_expected_output
raw_output = [0] * RAW_LEN

def xor():
   key = rand() & 0xFF
   for i in range(RAW_LEN):
      raw_output[i] = raw_input[i] ^ key

def add():
   key = rand() & 0xFF
   for i in range(RAW_LEN):
      raw_output[i] = (raw_input[i] + key) & 0xFF

def sub():
   key = rand() & 0xFF
   for i in range(RAW_LEN):
      raw_output[i] = (raw_input[i] - key) & 0xFF

def rotate_left():
   rotation = rand() % RAW_LEN
   for i in range(RAW_LEN):
      raw_output[i] = raw_input[(i + rotation) % RAW_LEN]

def rotate_right():
   rotation = rand() % RAW_LEN
   for i in range(RAW_LEN):
      raw_output[i] = raw_input[(i + RAW_LEN - rotation) % RAW_LEN]

operations = [xor, sub, add, rotate_right, rotate_left] # Inverted operation orders to invert them

NUM_OPERATIONS = len(operations)
NUM_ROUNDS = rand_used = NUM_OPERATIONS * 100

for round in reversed(range(NUM_ROUNDS)):
   operation = round % NUM_OPERATIONS
   operations[operation]()

   raw_input = raw_output.copy()

hex_output = bytes(raw_input).hex()

print("[+] hex_output", hex_output)
