H,M=map(int,input().split())
C=int(input())
x=(H*60+M+C)%(24*60)
print(x//60,x%60)