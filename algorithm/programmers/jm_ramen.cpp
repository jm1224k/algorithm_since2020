#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    
    int j = 0;
    for(int i = 0; i < k; i++)
    {
        if(dates[j] == i)
        {
            pq.push(supplies[j]);
            if (j != supplies.size() - 1)
                j++;
        }
        if(stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}
