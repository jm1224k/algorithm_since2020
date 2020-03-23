#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int i = 0, j = 0;
    sort(people.begin(), people.end());
    
    for (j = people.size()-1; j > i; j--) {
		if (people[j] + people[i] <= limit) {
			i += 1;
			answer += 1;
		}
		else {
			answer += 1;
		}
	}
	if (i == j)
		answer += 1;
    
    return answer;
}
