mp1={
    2:"double",
    3:"triple",
    4:"quadruple",
    5:"quintuple",
    6:"sextuple",
    7:"septuple",
    8:"octuple",
    9:"nonuple",
    10:"decuple",
    }
mp2={
    '0':"zero",
    '1':"one",
    '2':"two",
    '3':"three",
    '4':"four",
    '5':"five",
    '6':"six",
    '7':"seven",
    '8':"eight",
    '9':"nine"
    }

for tc in range(int(input())):
    print(f"Case #{tc+1}:",end=" ")
    s,t=input().split()
    t=list(map(int,t.split('-')))
    cnt,it,jt=0,0,0
    p='!'
    for c in s:
        if c==p:cnt+=1
        else:
            if cnt>10 or cnt==1:
                print(end=(mp2[p]+" ")*cnt)
            elif p!='!':
                print(end=mp1[cnt]+" "+mp2[p]+" ")
            cnt=1
            p=c
            
        jt+=1
        if jt==t[it]:
            jt=0
            it+=1
            if cnt>10 or cnt==1:print(end=(mp2[p]+" ")*cnt)
            else:print(end=mp1[cnt]+" "+mp2[p]+" ")
            
            cnt=1
            p='!'
            cnt=0
            
    print()
            
