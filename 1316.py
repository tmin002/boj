#!/usr/bin/python3
total = 0
for _ in range(int(input())):
    s = input()
    over = []
    prev = s[0]
    same = False

    for c in s:
        if prev != c:
            if c in over:
                same = True
                break 
            over.append(prev)
        prev = c
    
    if not same: total += 1
print(total)
