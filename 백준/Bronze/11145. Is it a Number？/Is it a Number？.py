for _ in range(int(input())):
    s=input()
    try:
        if int(s)<0:
            print("invalid input")
        else:print(int(s))
    except:
        print("invalid input")
