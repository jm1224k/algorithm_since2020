#include <vector>
#include <queue>

using namespace std;

vector<int> v[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, maximum = -1;
    vector<int> path(n+1);
    queue<int> q;
    //initialize
    fill(path.begin() + 2, path.end(), -1);
    path[1] = 0;
    //make graph
    for(int i = 0; i < edge.size(); i++)
    {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    //bfs
    q.push(1);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(int i = 0; i < v[now].size(); i++)
        {
            if(path[v[now][i]] != -1)
                continue;
            
            q.push(v[now][i]);
            path[v[now][i]] = path[now] + 1;
            
            if(maximum == -1 || maximum < path[v[now][i]])
                maximum = path[v[now][i]];
        }
    }
    //check
    for(int i = 2; i <= n; i++)
    {
        if(path[i] == maximum)
            answer++;
    }
    return answer;
}
