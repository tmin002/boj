"""
12345 -> 12534
[34]
[125]

12345678 -> 43687521
[12]
[]

"""

n = int(input())
l = [i for i in range(1, n+1)]
a, b, result = [], [], []
prt = ''
for i in range(n): result.append(int(input()))

widx = 0
for i in l:
    a.append(i)
    prt += '+\n'
    while len(a)!=0 and a[-1] == result[widx]:
        b.append(a.pop())
        widx += 1
        prt += '-\n'

if len(a) != 0: print('NO')
else: print(prt)