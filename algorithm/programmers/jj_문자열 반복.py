n = int(input())

for i in range(n):
    num, string = input().split()
    for s in string:
        print(s*int(num),end='')
    print()