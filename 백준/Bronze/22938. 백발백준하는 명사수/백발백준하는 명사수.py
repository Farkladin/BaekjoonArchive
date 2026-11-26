X1,Y1,R1=map(int,input().split())
X2,Y2,R2=map(int,input().split())
dist=(X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)
print("YES" if dist<(R1+R2)*(R1+R2) else "NO")