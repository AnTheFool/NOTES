for _ in range(int(input())):
    n, m = map(int, input().split())
    a = input()
    b = input()
    k = 0
    if a in b:
        print(len(a))
    else:
        while a[:k] in b:
            k += 1
        print(k - 1)