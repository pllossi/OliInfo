#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N = int(input().strip())

S = list(map(int, input().strip().split()))

ans = True
Q = [0 for i in range(4)]


# INSERT YOUR CODE HERE


if ans:
    print(*Q)
else:
    print(-1)

sys.stdout.close()
