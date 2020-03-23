#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool map[101][101] = {0, };
bool isVisit[101] = {0, };

int solution(int n, vector<vector<int>> results) {
    int answer = 0, tmp = 0, i = 0;
    int len = results.size();
    queue<int> q;
    //check
    for(i = 0; i < len; map[results[i][0]][results[i][1]] = 1, i++);
    
    for(i = 1; i <= n; i++)
    {
        tmp = 0;
        //check-in
        memset(isVisit, 0, sizeof(isVisit));
        isVisit[i] = 1;
        q.push(i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            
            for(int j = 1; j <= n; j++)
            {
                if(isVisit[j] == 1 || map[now][j] == 0)
                    continue;
                isVisit[j] = 1;
                tmp += 1;
                q.push(j);
            }
        }
        //check-out
        q.push(i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            
            for(int j = 1; j <= n; j++)
            {
                if(isVisit[j] == 1 || map[j][now] == 0)
                    continue;
                isVisit[j] = 1;
                tmp += 1;
                q.push(j);
            }
        }
        if(tmp == n - 1)
            answer++;
    }
    return answer;
}
