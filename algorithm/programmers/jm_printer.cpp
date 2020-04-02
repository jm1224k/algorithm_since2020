#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int i = 0, maxP = -1, check = 0, prior = 1;
    vector<int> d(101);
    
    for(i = 0; i < priorities.size(); i++)
    {
        if(maxP == -1 || maxP < priorities[i])
        {
            maxP = priorities[i];
            check = i;
        }
    }
    
    d[check] = prior++;
    if(location == check)
        return d[check];
    
    i = check + 1;
    while(1)
    {
        if(i == check)
            maxP -= 1;
        else if(d[i] == 0 && maxP == priorities[i])
        {
            check = i;
            d[i] = prior++;
        }
        
        if((d[i]!= 0 && i == location) || maxP == 0)
            break;
        
        i = (i + 1) % priorities.size();
    }
    return d[location];
}
