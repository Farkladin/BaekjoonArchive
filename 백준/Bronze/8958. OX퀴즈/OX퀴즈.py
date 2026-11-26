for _ in range(int(input())):
    s=input()
    cnt=0
    ans=0
    for x in s:
        if(x=='O'):cnt+=1
        else:cnt=0
        ans+=cnt
    print(ans)