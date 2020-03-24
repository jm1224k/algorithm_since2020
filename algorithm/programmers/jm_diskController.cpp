#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int solution(vector<vector<int>> jobs) {
    int answer = 0, i = 0, end = 0;
    
    auto comp = [](vector<int> a, vector<int> b) { return a.at(1) > b.at(1); };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    
    sort(jobs.begin(), jobs.end());
    
    while (i < jobs.size() || !pq.empty()) {
        if (jobs.size() > i && end >= jobs[i][0])
        {
            pq.push(jobs[i]);
            i += 1;
            continue;
        }

        if (!pq.empty())
        {
            end += pq.top()[1];
            answer += end - pq.top()[0];
            pq.pop();
        }
        else
            end = jobs[i][0];
    }
    return answer / jobs.size();
}
