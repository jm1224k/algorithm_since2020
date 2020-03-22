#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int total = (brown/2) + 2;
    
    for(int i = 3; i <= total/2; i++)
    {
        if(red == (i - 2) * (total - i - 2))
        {
            answer.push_back(total - i);
            answer.push_back(i);
            break;
        }        
    }
    return answer;
}
