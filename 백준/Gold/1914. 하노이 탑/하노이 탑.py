def f(n, x, y, z):
    if n == 0:return
    f(n-1,x,z,y)
    print(x,y)
    f(n-1,z,y,x)
n=int(input())
print(2**n-1)

if n<=20:f(n, 1, 3, 2)