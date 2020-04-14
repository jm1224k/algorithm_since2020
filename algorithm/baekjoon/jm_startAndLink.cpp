#include <iostream>

using namespace std;

int d[21][21] = { 0, };
bool check[21] = { false, };
int n;
int answer = -1;

int cal()
{
    int res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(check[i])
        {
            for(int j = 0; j < n; j++)
            {
                if(check[j])
                    res1 += d[i][j];
            }
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                if(!check[j])
                    res2 += d[i][j];
            }
        }
    }
    int ret = res1 < res2 ? res2 - res1 : res1 - res2;
    return ret;
}

void solve(int now, int cnt)
{
    if(now >= n)
    {
        if(cnt != n/2)
            return ;

        int res = cal();

        if(answer == -1 || res < answer)
            answer = res;
        
        return ;
    }
    
    check[now] = true;
    solve(now + 1, cnt + 1);

    check[now] = false;
    solve(now + 1, cnt);
}

int main(void)
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }

    solve(0, 0);

    cout << answer << endl;
}
