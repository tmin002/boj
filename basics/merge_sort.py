original = (234,345,456,456,234,567,468,7435,23,345,47,34,45,3)

def merge(list1, list2):
    i1, i2 = 0, 0
    rl = []

    while i1 < len(list1) and i2 < len(list2):
        if list1[i1] < list2[i2]:
            rl.append(list1[i1])
            i1 += 1
        else:
            rl.append(list2[i2])
            i2 += 1

    if i1 == len(list1):
        rl += list2[i2:]
    if i2 == len(list2):
        rl += list1[i1:]

    return rl

def merge_sort(ll):
    len_list = len(ll)
    if len_list > 2:
        left = merge_sort(ll[:int(len_list/2)])
        right = merge_sort(ll[int(len_list/2):])
        return merge(left, right)
    
    elif len_list == 2:
        if ll[0] < ll[1]:
            return ll
        else:
            return (ll[1], ll[0])

    else:
        return ll

print(merge_sort(original))
