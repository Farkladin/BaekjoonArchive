from decimal import Decimal, getcontext

getcontext().prec=200
PI=Decimal("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214")
eps=Decimal('15e-57')

FAC = [1]*400
for i in range(2,400):FAC[i]=FAC[i-1]*i

def COS(x):
    x=x%(2*PI)
    if x>PI:x-=2*PI
    x_sq=x*x
    term=Decimal(1)
    ret=term

    for n in range(1,101):
        term*=-x_sq/Decimal((2*n-1)*(2*n))
        ret+=term

    return ret;

def ASIN(x):
    x_sq=x*x
    term=x
    ret=x

    for n in range(1,101):
        nu=Decimal(FAC[2*n])
        de=(Decimal(4)**n)*(Decimal(FAC[n])**2)*(2*n+1)
        ret+=nu/de*(x**(2*n+1))
        
    return ret
        
def ACOS(x):
    x_sq=x*x
    if x>=1:return Decimal(0)
    if x<=-1:return PI
    if x>Decimal('0.7'):return ASIN((1-x*x).sqrt())
    elif x<Decimal('-0.7'):return PI-ASIN((1-x*x).sqrt())
    else:return PI*Decimal(0.5)-ASIN(x)
    
def sol(a,b,c,d):
    
    p=(3*a*c-b*b)/(3*a*a)
    q=(2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a)
    D=q*q*Decimal(0.25)+p*p*p/27
    arr=[]
    if D>eps:
        sqrtD=D.sqrt()
        u_base=-q*Decimal(0.5)+sqrtD
        v_base=-q*Decimal(0.5)-sqrtD

        u=u_base**(Decimal(1)/Decimal(3)) if u_base>=-eps else -((-u_base)**(Decimal(1)/Decimal(3)))
        v=v_base**(Decimal(1)/Decimal(3)) if v_base>=-eps else -((-v_base)**(Decimal(1)/Decimal(3)))

        t=u+v
        x=t-b/(3*a)
        arr.append(x)
    else:
        if abs(p)<eps:arr.append(-b/(3*a))
        else:
            r=2*(-p/3).sqrt()
            val=(3*q)/(2*p*Decimal(-p/Decimal(3)).sqrt())
            val=max(Decimal(-1),min(Decimal(1),val))
            theta=Decimal(ACOS(val))/Decimal(3)
            
            t1=r*Decimal(COS(theta))
            t2=r*Decimal(COS(theta-2*PI/Decimal(3)))
            t3=r*Decimal(COS(theta-4*PI/Decimal(3)))

            shift=b/(3*a)
            arr.append(t1-shift)
            arr.append(t2-shift)
            arr.append(t3-shift)
            
    ans=[]
    for xx in arr:
        x=Decimal(xx)
        for _ in range(1000):
            fx=a*x*x*x+b*x*x+c*x+d
            dfx=3*a*x*x+2*b*x+c
            if abs(dfx)<eps:break
            diff=fx/dfx
            x-=diff

        ans.append(x)

    ans.sort()
    pre=-1/eps
    for r in ans:
        if pre+Decimal(1e-17)<r:
            print(end=f"{r:.10f} ")
            pre=r
    print()

for _ in range(int(input())):
    a,b,c,d=map(Decimal,input().split())
    sol(a,b,c,d)
