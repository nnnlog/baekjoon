import math

def g(x):
    return int(x * (x + 1) // 2) ** 2

def find_min(l):
    s = 1
    e = 2 ** 63
    l = 10 ** (l - 1)
    while s < e:
        mid = (s + e) >> 1
        if l <= g(mid):
            e = mid
        else:
            s = mid + 1
    return s

def init():
    global arr
    arr = [0 for i in range(78)]
    arr[0] = -1
    for i in range(2, 78):
        arr[i] = find_min(i)

def cnt(mid):
    if mid < 0:
        return 0
    c = 0
    i = 2
    while arr[i] <= mid:
        c += (arr[i] - arr[i - 1]) * (i - 1)
        i += 1
    c += (mid - arr[i - 1] + 1) * (i - 1)
    return c

def optimizing(n):
    init()
    s = 0
    e = 2 ** 63
    while s < e:
        mid = (s + e) >> 1
        #print(mid, cnt(mid))
        if cnt(mid) < n:
            s = mid + 1
        else:
            e = mid
    #print(s, g(s), cnt(s - 1), n - cnt(s - 1) - 1)
    return int(str(g(s))[n - cnt(s - 1) - 1])
    