cur,mn=0,0
for i in range(int(input())):
    cur+=int(input())
    mn=max(mn,-cur)
print(mn)