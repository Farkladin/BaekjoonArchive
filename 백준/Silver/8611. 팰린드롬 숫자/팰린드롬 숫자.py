n=int(input())
flag=False
for i in range(2,11):
    cur=""
    m=n
    while m:
        cur+=str(m%i)
        m//=i
    if(cur==cur[::-1]):
        flag=True
        print(i,cur)

if(not flag):print("NIE")
