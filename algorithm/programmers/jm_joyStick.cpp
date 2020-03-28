#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0, j = 0, cur = 0;
    vector<int> v;
    
    for(i = 0; i < name.size(); i++)
        v.push_back(min(int(name[i]) - 65, 91 - int(name[i])));
        
    answer += v[cur];
    v[cur] = 0;
    
    while(1)
    {
        for(i = 0; i < v.size(); i++)
            if(v[i] != 0)
                break;
        
        if(i == v.size())
            break;
        
        i = 1;
        while(v[(cur + i) % v.size()] == 0)
            i++;
            
        j = 1;
        while(v[(cur - j + v.size())%v.size()] == 0)
            j++;
        
        cur = i <= j ? (cur + i) % v.size() : (cur - j + v.size())%v.size();
        answer += min(i, j) + v[cur];
        v[cur] = 0;
    }
    return answer;
}
