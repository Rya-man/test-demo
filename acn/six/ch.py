def c(d):
    s=0
    for i in range(0,len(d),2):
        w=(d[i]<<8)+(d[i+1] if i+1<len(d) else 0)
        s=(s+w)&0xffff
    return (~s)&0xffff
