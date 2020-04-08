def hanoi(n,a,b,c):
    if n==1:
        move.append([a,b,c])
    else:
        hanoi(n-1,a,c,b)
        move.append([a,b,c])
        hanoi(n-1,b,a,c)

move = []
hanoi(3,1,2,3)

print(len(move))
print("\n".join([' '.join(str(i) for i in row) for row in move]))