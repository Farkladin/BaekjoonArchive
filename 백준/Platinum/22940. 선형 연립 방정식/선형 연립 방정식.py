from fractions import Fraction as Frac
import copy

def LUP_Decomposition(refA):
    A = copy.deepcopy(refA)
    n=len(A)
    kk=0

    pi = [i for i in range(n)]
        
    for k in range(n):
        p=Frac(0,1)
        for i in range(k,n):
            if(abs(A[i][k])>p):
                p=abs(A[i][k])
                kk=i

        pi[k],pi[kk]=pi[kk],pi[k]

        for i in range(n):
            A[k][i],A[kk][i]=A[kk][i],A[k][i]

        for i in range(k+1,n):
            A[i][k] /= A[k][k]
            for j in range(k+1,n):
                A[i][j] -= A[i][k]*A[k][j]

    return A,pi


def SLE_Solver(refA, refb):
    A = copy.deepcopy(refA)
    b = copy.deepcopy(refb)

    n = len(A)
    LU, pi = LUP_Decomposition(A)
    L = copy.deepcopy(LU)
    U = copy.deepcopy(LU)

    for i in range(n):
        for j in range(n):
            if i>j: U[i][j]=Frac(0)
            else: L[i][j]=Frac(0)

    x = [Frac(0,1)] * n
    y = [Frac(0,1)] * n

    for i in range(n):
        y[i] = b[pi[i]]
        for j in range(i):
            y[i] -= L[i][j]*y[j]

    for i in range(n-1,-1,-1):
        x[i]=y[i]
        for j in range(n-1,i,-1):
            x[i] -= U[i][j]*x[j]
        x[i] /= U[i][i]

    return x


N = int(input())
A = []
b = []
for i in range(N):
    a=list(map(Frac,input().split()))
    A.append(a[:N])
    b.append(a[N])

X = SLE_Solver(A,b)
for x in X:print(int(x),end=' ')
