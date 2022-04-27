def ok(a, b, c, d, e, f):
    #print(a, b, c, d, e, f, a * d + c * f + b * e - b * c - d * e - a * f)
    return a * d + c * f + b * e - b * c - d * e - a * f > 0

def convex4gon(L):
    sz = len(L)
    ans = 0
    for i in range(sz):
        for j in range(i + 1, sz):
            for k in range(j + 1, sz):
                for l in range(k + 1, sz):
                    for x in range(0, 6):
                        if x == 0:
                            if ok(L[i][0], L[i][1], L[j][0], L[j][1], L[k][0], L[k][1]) * ok(L[j][0], L[j][1], L[k][0], L[k][1], L[l][0], L[l][1]) * ok(L[k][0], L[k][1], L[l][0], L[l][1], L[i][0], L[i][1]) * ok(L[l][0], L[l][1], L[i][0], L[i][1], L[j][0], L[j][1]) == 0:
                                continue
                        if x == 1:
                            if ok(L[i][0], L[i][1], L[j][0], L[j][1], L[l][0], L[l][1]) * ok(L[j][0], L[j][1], L[l][0], L[l][1], L[k][0], L[k][1]) * ok(L[l][0], L[l][1], L[k][0], L[k][1], L[i][0], L[i][1]) * ok(L[k][0], L[k][1], L[i][0], L[i][1], L[j][0], L[j][1]) == 0:
                                continue
                        elif x == 2:
                            if ok(L[i][0], L[i][1], L[k][0], L[k][1], L[j][0], L[j][1]) * ok(L[k][0], L[k][1], L[j][0], L[j][1], L[l][0], L[l][1]) * ok(L[j][0], L[j][1], L[l][0], L[l][1], L[i][0], L[i][1]) * ok(L[l][0], L[l][1], L[i][0], L[i][1], L[k][0], L[k][1]) == 0:
                                continue
                        elif x == 3:
                            if ok(L[i][0], L[i][1], L[k][0], L[k][1], L[l][0], L[l][1]) * ok(L[k][0], L[k][1], L[l][0], L[l][1], L[j][0], L[j][1]) * ok(L[l][0], L[l][1], L[j][0], L[j][1], L[i][0], L[i][1]) * ok(L[j][0], L[j][1], L[i][0], L[i][1], L[k][0], L[k][1]) == 0:
                                continue
                        elif x == 4:
                            if ok(L[i][0], L[i][1], L[l][0], L[l][1], L[j][0], L[j][1]) * ok(L[l][0], L[l][1], L[j][0], L[j][1], L[k][0], L[k][1]) * ok(L[j][0], L[j][1], L[k][0], L[k][1], L[i][0], L[i][1]) * ok(L[k][0], L[k][1], L[i][0], L[i][1], L[l][0], L[l][1]) == 0:
                                continue
                        elif x == 5:
                            if ok(L[i][0], L[i][1], L[l][0], L[l][1], L[k][0], L[k][1]) * ok(L[l][0], L[l][1], L[k][0], L[k][1], L[j][0], L[j][1]) * ok(L[k][0], L[k][1], L[j][0], L[j][1], L[i][0], L[i][1]) * ok(L[j][0], L[j][1], L[i][0], L[i][1], L[l][0], L[l][1]) == 0:
                                continue
                        ans += 1
                        #print(i, j, k, l, x, "ok")
                        break
                    #if (ok(L[k][0], L[k][1], L[l][0], L[l][1], L[i][0], L[i][1]) == False):
                    #    continue
                    #if (ok(L[l][0], L[l][1], L[k][0], L[k][1], L[j][0], L[j][1]) == False):
                    #    continue
    return ans
