import string


N = int(input())

ans = N
for _ in range(N):
    S = input().lower()
    dictatus = dict()
    for c in S:
        if c not in string.ascii_letters:
            continue
        if c not in dictatus:
            dictatus[c] = 1
        else:
            dictatus[c] += 1
        
        if dictatus[c] > 2:
            ans -= 1
            break

print(ans)
