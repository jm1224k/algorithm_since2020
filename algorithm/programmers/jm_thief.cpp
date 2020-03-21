#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    vector <int> first;
	vector <int> second;
    
	int len = money.size();
	first.push_back(money[0]);
    first.push_back(money[0]);
    second.push_back(0);
	second.push_back(money[1]);
	
	for (int i = 2; i < len - 1; i++)
		first.push_back(max(first[i - 2] + money[i], first[i - 1]));
                            
	for (int i = 2; i < len; i++)
		second.push_back(max(second[i - 2] + money[i], second[i - 1]));

	return max(first[len - 2], second[len - 1]);
}
