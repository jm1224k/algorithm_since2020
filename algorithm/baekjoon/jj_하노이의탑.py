def hanoi(n,start,via,end):
    if n==1:
        move.append([start,end])
    else:
        hanoi(n-1,start,end,via)
        move.append([start,end])
        hanoi(n-1,via,start,end)

move = []
hanoi(int( input() ),1,2,3)

print(len(move))
print("\n".join([' '.join(str(i) for i in row) for row in move]))