#1 리스트
def solution(board):
    """N: 세로, M:가로 , board: 체스판 배열"""
    start_w = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]

    start_b = [['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
               ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
               ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]
    cnt_w = 0
    cnt_b = 0
    for i in range(8):
        for j in range(8):
            if board[i][j] != start_w[i][j]:
                cnt_w +=1
            if board[i][j] != start_b[i][j]:
                cnt_b +=1
    return min(cnt_w,cnt_b)

N,M = map(int,input().split())
first_board = [list(input()) for _ in range(N)]

min_answer = 64

for x in range(N-7):
    for y in range(M-7):
        second_board = list(first_board[x+a][y:y+8] for a in range(8))
        print(x,y)
        # print(second_board)
        answer = solution(second_board)
        min_answer = min(answer, min_answer)

print(min_answer)