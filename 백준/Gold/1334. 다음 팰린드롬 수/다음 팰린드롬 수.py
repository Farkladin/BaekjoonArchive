N=input()
t=len(N)//2
flag=len(N)%2==0
a=""

if flag:
    a=N[:t]
    if int(a+a[::-1])>int(N):print(a+a[::-1])
    else:
        a=str(int(a)+1)
        b=a[::-1]
        if len(a)>t:a=a[:t]
        print(a+b)
else:
    t+=1
    a=N[:t]
    b=a[t-2::-1]
    if t-2<0:b=""
    if int(a+b)>int(N):print(a+b)
    else:
        a=str(int(a)+1)
        if len(a)>t:
            a=a[:t]
            b=a[::-1]
        else:
            b=a[t-2::-1]
            if t-2<0:b=""
        print(a+b)

