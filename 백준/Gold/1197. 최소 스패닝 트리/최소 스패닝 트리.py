import sys
from collections import deque
sys.setrecursionlimit(1<<20)
input=sys.stdin.readline
def sol1():
    z=1
    for _z_ in range(z):
        V,E=map(int,input().split())
        pos=[i for i in range(0,3+V)]
        def find(x):
            t=x
            while t!=pos[t]:t=pos[t]
            while x!=pos[x]:
                tmp,x=x,pos[x]
                pos[tmp]=t
            return t

        def uni(x,y):
            x=find(x)
            y=find(y)
            pos[y]=x
    
        edges=[]
        for _ in range(E):
            a,b,c=map(int,input().split())
            edges.append((c,a,b))

        edges.sort()
        ans=0
        for w,u,v in edges:
            if find(u)!=find(v):
                uni(u,v)
                ans+=w

        print(ans)
sol1()