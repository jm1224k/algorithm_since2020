#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    
    for(int i = 0; i < heights.size(); i++)
    {
        if(s.empty())
        {
            answer.push_back(0);
            s.push(i+1);
        }
        else
        {
            while(!s.empty())
            {
                if(heights[i] < heights[s.top() - 1])
                    break;
                s.pop();
            }
            
            if(s.empty())
                answer.push_back(0);
            else
                answer.push_back(s.top());
            
            s.push(i + 1);
        }
    }
    return answer;
}
