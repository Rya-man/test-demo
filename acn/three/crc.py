def c(d, g):
    d += '0'*(len(g)-1)
    darr = strtoint(d)
    darr2 = strtoint(d)
    
    garr = strtoint(g)
    x = len(g)
    for i in range(len(darr)-x+1):
        if darr2[i] == 1:
            for j in range(x):
                darr[i+j] = darr[i+j] ^ garr[j]
    
    remainder = darr[-(x-1):]
    return inttostr(remainder)

def strtoint(d):
    return [1 if i == '1' else 0 for i in d]

def inttostr(d):
    return ''.join('1' if i == 1 else '0' for i in d)
