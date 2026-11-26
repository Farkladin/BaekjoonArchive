from decimal import *
getcontext().prec=1503
a,b=map(Decimal,input().split())
print(a/b)