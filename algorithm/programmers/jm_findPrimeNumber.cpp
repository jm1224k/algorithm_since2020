#include <string>
#include <vector>
#include <algorithm>

#define MAX_NUM 10000000

using namespace std;

int isUsed[7] = {0, };
bool prime_number[MAX_NUM] = {0, };

int solution(string numbers) {
    int answer = 0;
    
    //string to integer
    sort(numbers.begin(), numbers.end(), greater<char>());
    int number = stoi(numbers);
    
    //소수 판별
    prime_number[0] = 1;
    prime_number[1] = 1;
    
    for(int i = 2; i <= number; i++)
    {
        if(prime_number[i] == 1)
            continue;
        
        int index = i;
        for(int j = 2; i * j <= number; index = i * j, prime_number[index] = 1, j++);
    }
    
    //조합
    sort(numbers.begin(), numbers.end());
    vector<int> v;
    
    for(int i = 1; i < numbers.size() + 1; i++)
    {        
        do{
            string tmp = numbers.substr(0, i);
            if(!prime_number[stoi(tmp)])
            {
                prime_number[stoi(tmp)] = 1;
                answer += 1;
            }
        }while(next_permutation(numbers.begin(), numbers.end()));
    }
    return answer;
}
