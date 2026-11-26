for _ in range(int(input())):
    a=int(input())
    b=a
    while a>=100:
        print(a)
        a=a//10-a%10
    print(a)
    print("The number",b,f"is {"" if a==11 else "not "}divisible by 11.\n")
