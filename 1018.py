raw = input().split()
m,n = int(raw[0]), int(raw[1])
wl = ['WBWBWBWB', 'BWBWBWBW']
iw = [wl[x%2] for x in range(8)]
ib = [wl[(x+1)%2] for x in range(8)]
min = 99999999

board = []
for i in range(m):
    board.append(input())

for mi in range(m-8+1):
    for ni in range(n-8+1):
        wcnt = 0
        for i in range(8):
            for j in range(8):
                if iw[i][j] != board[mi+i][ni+j]:
                    wcnt += 1
        bcnt = 0
        for i in range(8):
            for j in range(8):
                if ib[i][j] != board[mi+i][ni+j]:
                    bcnt += 1
        small = wcnt if wcnt < bcnt else bcnt
        if small < min:
            min = small
                    
print(min)