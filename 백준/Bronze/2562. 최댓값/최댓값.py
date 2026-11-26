idx,mx=-1,-(1<<31)
for i in range(1,10):
    x=int(input())
    if mx<x:
        idx=i
        mx=x
print(mx)
print(idx)