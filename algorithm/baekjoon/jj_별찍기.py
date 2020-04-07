
def concatenate(r1,r2):
    return [''.join(x) for x in zip(r1,r2,r1)]

def star10(N):
    if N == 1:
        return ['*']
    N //= 3
    x = star10(N)
    top_bottom = concatenate(x,x)
    middle = concatenate(x,[' '*N]*N)
    return top_bottom + middle + top_bottom

print('\n'.join(star10(27)))

# def star(N):
#     #TODO
#     stars = ''
#     def blank(N):
#         if N == 3:
#             blanks = ' ' * (N / 3)
#         else:
#             blanks = ' '*(N/3)+'\n'
#             blanks = blanks*(N/3)
#         return blanks
#
#     #탈출구
#     if N == 3:
#         if N%3 == 0:
#             return '***\n'
#         elif N%3 == 1:
#             return '*'+blank(N)+'*\n'
#         elif N%3 == 2:
#             return '***'
#         # return '***\n* *\n***'
#     else:
#         if N%3 == 0:
#             return star(int(N//3))+star(int(N//3))+star(int(N//3)) + '\n'
#         elif N%3 == 1:
#             return star(int(N/3))+blank(N)+star(int(N/3)) + '\n'
#         elif N%3 == 2:
#             return star(int(N/3))+star(int(N/3))+star(int(N/3))
#
#
# def solution(N):
#     s = star(N)
#     print(s)
#     # for n in range(N):
#     #     print(star(n))
#
# solution(8)




