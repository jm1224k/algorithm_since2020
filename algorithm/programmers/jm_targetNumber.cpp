#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> numbers, int target, int sum, int now)
{
    if(now == numbers.size())
    {
        if(sum == target)
            answer += 1;
    }
    else
    {
        sum += numbers[now];
        dfs(numbers, target, sum, now + 1);
        
        sum -= 2 * numbers[now];
        dfs(numbers, target, sum, now + 1);
        
        sum += numbers[now];
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}
