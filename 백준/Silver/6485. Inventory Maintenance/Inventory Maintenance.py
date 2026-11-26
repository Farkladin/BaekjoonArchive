from decimal import Decimal as Dec
from decimal import getcontext
getcontext().prec=20
mp={}
profit=Dec(0)
while 1:
    line=input().split()
    if line[0]=="*":break

    
    if line[0]=="new":
        mp[line[1]]=[Dec(line[2]),Dec(line[3]),0]
    elif line[0]=="delete":
        profit-=mp[line[1]][0]*Dec(mp[line[1]][2])
        mp.pop(line[1])
    elif line[0]=="buy":
        mp[line[1]][2]+=int(line[2])
    elif line[0]=="sell":
        n=min(mp[line[1]][2],int(line[2]))
        profit+=(mp[line[1]][1]-mp[line[1]][0])*Dec(n)
        mp[line[1]][2]-=n
    elif line[0]=="report":
        mp=dict(sorted(mp.items()))
        print("                  INVENTORY REPORT")
        print("Item Name     Buy At      Sell At      On Hand        Value")
        print("---------     ------      -------      -------        -----")
        tmp=Dec(0)
        for x in mp:
            print(f"{x:<12}{mp[x][0]:>8}{mp[x][1]:>13}{mp[x][2]:>13}{Dec(mp[x][2])*mp[x][0]:>13}")
            tmp+=Dec(mp[x][2])*mp[x][0]

        print("------------------------")
        print(f"Total value of inventory{tmp:>35}")
        print(f"Profit since last report{profit:>35}\n")
        profit=0
