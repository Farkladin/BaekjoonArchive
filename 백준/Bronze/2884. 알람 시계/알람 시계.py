H,M=map(int,input().split())
x=(H*60+M-45+24*60)%(24*60)
print(x//60,x%60)