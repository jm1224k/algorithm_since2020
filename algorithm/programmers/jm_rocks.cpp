#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int distance, vector<int> rocks, int n, int min_dist)
{
    int cnt = 0, temp = 0;
    for(int i = 0; i < rocks.size(); i++)
    {
        if(((i == rocks.size()) && (distance - temp < min_dist)) || (rocks[i] - temp < min_dist))
            cnt += 1;
        else
            temp = rocks[i];        
        if(cnt > n)
            return false;
    }
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int lo = 0, hi = distance, mid;
    while(lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        if(check(distance, rocks, n, mid))
            lo = mid;
        else
            hi = mid;
    }
    return (check(distance, rocks, n, hi)) ? hi : lo;
}
