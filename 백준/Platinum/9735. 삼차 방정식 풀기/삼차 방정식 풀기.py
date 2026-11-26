from decimal import Decimal, getcontext
import math
getcontext().prec=100

def sol(a,b,c,d):
    eps=Decimal('15e-57')
    p=(3*a*c-b*b)/(3*a*a)
    q=(2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a)
    D=q*q*Decimal(0.25)+p*p*p/27
    arr=[]
    if D>eps:
        sqrtD=D.sqrt()
        u_base=-q*Decimal(0.5)+sqrtD
        v_base=-q*Decimal(0.5)-sqrtD

        u=u_base**Decimal(1/3) if u_base>=-eps else -((-u_base)**Decimal(1/3))
        v=v_base**Decimal(1/3) if v_base>=-eps else -((-v_base)**Decimal(1/3))

        t=u+v
        x=t-b/(3*a)
        arr.append(x)
    else:
        if abs(p)<eps:arr.append(-b/(3*a))
        else:
            r=2*(-p/3).sqrt()
            val=(3*q)/(2*p*Decimal(-p/3).sqrt())
            val=max(Decimal(-1),min(Decimal(1),val))
            theta=math.acos(val)/3

            pi=math.pi
            t1=r*Decimal(math.cos(theta))
            t2=r*Decimal(math.cos(theta-2*pi/3))
            t3=r*Decimal(math.cos(theta-4*pi/3))

            shift=b/(3*a)
            arr.append(t1-shift)
            arr.append(t2-shift)
            arr.append(t3-shift)
            
    ans=[]
    for xx in arr:
        x=Decimal(xx)
        for _ in range(100):
            fx=a*x*x*x+b*x*x+c*x+d
            dfx=3*a*x*x+2*b*x+c
            if abs(dfx)<eps:break
            diff=fx/dfx
            x-=diff

        ans.append(x)

    ans.sort()
    pre=-1/eps
    for r in ans:
        if pre+Decimal(1e-9)<r:
            print(end=f"{r:.10f} ")
            pre=r
    print()

for _ in range(int(input())):
    a,b,c,d=map(Decimal,input().split())
    sol(a,b,c,d)
