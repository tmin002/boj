for _ in range(int(input())):
    n, idx = [int(i) for i in input().split()]
    l = [int(i) for i in input().split()]
    q = []
    for index, imp in enumerate(l): q.insert(0, (imp, index))

    printed_cnt = 0
    while True:
        current = q[-1][0]
        needswap = False
        for i in q:
            if i[0] > current:
                needswap = True
                break
        
        if needswap: q.insert(0, q.pop())
        else:
            printed_cnt += 1
            if q[-1][1] == idx: break
            else: q.pop()

    print(printed_cnt)