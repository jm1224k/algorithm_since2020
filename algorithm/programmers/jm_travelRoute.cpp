#include <string>
#include <vector>

using namespace std;

int len;
vector<vector<string>> _tickets;

bool isUsed[10001] = { 0, };

vector<string> answer;

void dfs(int n, vector<string> now)
{
    if(now.size() == len + 1)
    {
        if(answer.size() == 0)
            answer = now;
        else
            answer = now < answer ? now : answer;

        return;
    }
    
    for(int i = 0; i < len; i++)
    {
        if(isUsed[i] == 1 || now[now.size() - 1] != _tickets[i][0])
            continue;
        
        isUsed[i] = 1;
        now.push_back(_tickets[i][1]);
        
        dfs(n + 1, now);
        
        isUsed[i] = 0;
        now.pop_back();
    }
}
    

vector<string> solution(vector<vector<string>> tickets)
{
    len = tickets.size();
    _tickets = tickets;
    
    vector<string> now;
    
    for(int i = 0; i < len; i++)
    {
        if(tickets[i][0] != "ICN")
            continue;
        
        isUsed[i] = 1;
        now.push_back(tickets[i][0]);
        now.push_back(tickets[i][1]);
        
        dfs(0, now);
        
        isUsed[i] = 0;
        now.pop_back();
        now.pop_back();
    }
    return answer;
}
