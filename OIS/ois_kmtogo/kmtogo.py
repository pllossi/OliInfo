#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N = int(input().strip())

D = [0 for i in range(10)]


# INSERT YOUR CODE HERE


for i in range(10):
    print(D[i], end=' ')
print()

sys.stdout.close()
