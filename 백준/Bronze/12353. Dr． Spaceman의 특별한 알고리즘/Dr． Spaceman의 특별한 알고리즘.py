for _ in range(int(input())):
    a,A,B=input().split()
    A1,A2=A.split('\'')
    A1=int(A1)
    A2=int(A2[:len(A2)-1:])
    B1,B2=B.split('\'')
    B1=int(B1)
    B2=int(B2[:len(B2)-1:])
    A=A1*12+A2
    B=B1*12+B2
    tmp=A+B
    if a=="B":
        tmp+=5
    else:
        tmp-=5

    le,ri=0,0
    if tmp%2==0:
        le=tmp//2-4
        ri=tmp//2+4
    else:
        le=tmp//2-3
        ri=tmp//2+4

    print(f"Case #{_+1}: {le//12}\'{le%12}\" to {ri//12}\'{ri%12}\"")
