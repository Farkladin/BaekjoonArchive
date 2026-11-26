from fractions import Fraction as frac
N=int(input())
arr=list(map(int,input().split()))
def f(i):
    global N
    if i==N:return 0
    return frac(1)/(frac(arr[i])+f(i+1))

x=1-f(0)
print(x.numerator,x.denominator)
