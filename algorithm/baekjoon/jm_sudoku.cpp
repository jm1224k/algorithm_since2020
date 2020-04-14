#include <iostream>

using namespace std;

int board[9][9] = { 0, };
bool row[9][10] = { false, };
bool col[9][10] = { false, };
bool square[9][10] = { false, };

int squareIdx(int x, int y)
{
    return (x / 3) * 3 + y / 3;
}

void backtracking(int now)
{
    if(now == 81)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }

    int x = now / 9;
    int y = now % 9;

    if(board[x][y])
        backtracking(now + 1);

    else if(board[x][y] == 0)
    {
        for(int k = 1; k <= 9; k++)
        {
            if(row[x][k] || col[y][k] || square[squareIdx(x, y)][k])
                continue;

            board[x][y] = k;
            row[x][k] = true;
            col[y][k] = true;
            square[squareIdx(x, y)][k] = true;

            backtracking(now + 1);
            
            board[x][y] = 0;
            row[x][k] = false;
            col[y][k] = false;
            square[squareIdx(x, y)][k] = false;
        }
    }
}

int main(void)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];

            row[i][board[i][j]] = true;
            col[j][board[i][j]] = true;
            square[squareIdx(i, j)][board[i][j]] = true;
        }
    }

    backtracking(0);

    return 0;
}
