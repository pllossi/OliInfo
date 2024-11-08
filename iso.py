import string


N = int(input())

ans = N
for _ in range(N):
    S = input().lower()
    sus = dict()
    for c in S:
        if c not in string.ascii_letters:
            continue
        if c not in sus:
            sus[c] = 1
        else:
            sus[c] += 1
        
        if sus[c] > 2:
            ans -= 1
            break

print(ans)
