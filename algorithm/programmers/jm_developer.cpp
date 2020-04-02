#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int last = 0, day = 0, now = -1, ret = 0;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        last = 100 - progresses[i];
        day = last % speeds[i] ? last / speeds[i] + 1 : last / speeds[i];
        
        if(now == -1 || now < day)
        {
            if(now == -1)
                ret = 1;
            else
            {
                answer.push_back(ret);
                ret = 1;
            }
            now = day;
        }
        else
            ret += 1;
    }
    answer.push_back(ret);
    
    return answer;
}
