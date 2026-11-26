for _ in range(int(input())):
    p=input()
    n=int(input())
    arr=input()
    arr=arr[1:len(arr)-1].split(',')
    le,ri=0,n-1
    idx=0
    flag=False
    for op in p:
        if op=='R':
            if le==idx:idx=ri
            elif ri==idx:idx=le
        elif idx==le:
            idx+=1
            le+=1
        else:
            idx-=1
            ri-=1

        if le>ri+1:
            flag=True
            break

    if flag:print("error")
    else:
        arr=arr[le:ri+1]
        if idx==ri:arr=arr[::-1]
        if len(arr)==0:print("[]")
        else:
            print(end='['+arr[0])
            for i in range(1,len(arr)):print(end=","+arr[i])
            print("]")
