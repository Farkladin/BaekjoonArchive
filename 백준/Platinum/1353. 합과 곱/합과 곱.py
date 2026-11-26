S,P=map(int,input().split())
if S==P:print(1)
else:
    ans=-1
    for n in range(2,S+2):
        if S/n < 1:break
        cur=(S/n)**n
        if cur+1e-9>=P:
            ans=n
            break
    print(ans)