#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    int num;
    vector<int> answer;
    deque<int> dq;
    
    for(int i = 0; i < operations.size(); i++)
    {
        num = stoi(operations[i].substr(2));
        if(operations[i][0] == 'I')
        {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else
        {
            if(dq.empty())
                continue;
            
            if(num == 1)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
    
    if(dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}
