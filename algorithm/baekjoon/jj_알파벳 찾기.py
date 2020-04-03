words = input()
alp = [-1 for _ in range(26)]
for i in range(len(words)):

    idx = ord(words[i])-97

    if alp[idx] != -1:
        continue
    else:
        alp[idx] = i
for a in alp:
    print(a,end=' ')

# for d in range(ord("a"), ord("z")+1):
#     p = a.find(chr(d))
#     print(p, end=" ")