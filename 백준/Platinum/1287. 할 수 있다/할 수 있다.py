A=input()
arr=[]
cnt=0
for i in A:
    if len(arr)==0:
        arr.append(i)
        continue
    
    if i.isdigit():
        if arr[cnt].isdigit():
            arr[cnt]+=i
        else:
            cnt+=1
            arr.append(i)
    else:
        arr.append(i)
        cnt+=1

for i in range(len(arr)):
    if arr[i]=='(' and i>0:
        if arr[i-1].isdigit() or arr[i-1]==')':
            print('ROCK')
            exit()
    if arr[i]==')' and i+1<len(arr):
        if arr[i+1].isdigit() or arr[i+1]=='(':
            print('ROCK')
            exit()
            
prec={'*':3,'/':3,'+':2,'-':2,'(':1}
stk=[]
post=[]
try:
    for c in arr:
        if c.isdigit():
            post.append(c)
        elif c=='(':
            stk.append(c)
        elif c==')':
            while stk and stk[-1]!='(':
                post.append(stk.pop())
            stk.pop()
        else:
            while stk and prec[stk[-1]]>=prec[c]:post.append(stk.pop())
            stk.append(c)
            
    while stk:post.append(stk.pop())
except:
    print('ROCK')
    exit()

stk=[]

try:
    for c in post:
        if c.isdigit():stk.append(int(c))
        else:
            op2=stk.pop()
            op1=stk.pop()

            if c=='+':stk.append(op1+op2)
            elif c=='-':stk.append(op1-op2)
            elif c=='*':stk.append(op1*op2)
            elif c=='/':stk.append(op1//op2)
    print(stk[0])
except:
    print('ROCK')
    exit()
