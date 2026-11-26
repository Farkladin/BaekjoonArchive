for _ in range(int(input())):
    x,y=map(int,input().split())
    fac=1
    for i in range(1,x+1):fac*=i
    fac=str(fac)
    cnt=0
    for c in fac:
        if c==str(y):cnt+=1
    print(cnt)
