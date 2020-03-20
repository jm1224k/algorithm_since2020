#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isVisit[201] = {0, };

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    
    for(int i = 0; i < n; i++)
    {
        if(isVisit[i] != 0)
            continue;
        
        q.push(i);
        answer += 1;
        
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            
            for(int j = 0; j < n; j++)
            {
                if(computers[now][j] == 0 || isVisit[j] != 0)
                    continue;
                
                isVisit[j] = 1;
                q.push(j);
            }
        }
    }
    return answer;
}
