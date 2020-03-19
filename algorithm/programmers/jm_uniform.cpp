#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int i = 0;
    int student[32] = {0, };
    
    for(i = 0; i < lost.size(); student[lost[i]] = -1, i++);
    for(i = 0; i < reserve.size(); i++)
    {
        if(student[reserve[i]] == -1)
            student[reserve[i]] = 0;
        else
            student[reserve[i]] = 1;
    }
    
    for(i = 1; i <= n; i++)
    {
        if(student[i] == -1)
        {
            if(student[i-1] == 1)
            {
                student[i] = 0;
                student[i-1] = 0;
            }
            else if(student[i+1] == 1)
            {
                student[i] = 0;
                student[i+1] = 0;
            }
            else
                continue;
        }
    }
    
    for(i = 1; i <= n; i++)
    {
        if(student[i] == 0 || student[i] == 1)
            answer += 1;
    }
    
    return answer;
}
