def solve(t, x, v):
    if x >= finish:
        return (t + 1) % 2
    if dp[t][int(x * 2)][v] != -1:
        return dp[t][int(x * 2)][v]
    dp[t][int(x * 2)][v] = (t + 1) % 2
    if solve(t + 1, x + v, v) == t % 2 or solve(t + 1, x + v + ac / 2, v + ac) == t % 2:
        dp[t][int(x * 2)][v] = t % 2
    return dp[t][int(x * 2)][v]

def ALSDJFKSND(x,v,a):
    global finish
    finish = x
    global ac
    ac = a
    global dp
    dp = [[[-1 for i in range(201)] for i in range(201)] for i in range(101)]
    
    if solve(1, v, v) == 0:
        return "D"
    x = solve(2, v + v, v)
    y = solve(2, v + v + a / 2, v + a)
    if x and y:
        return "C"
    if x:
        return "A"
    return "B"
