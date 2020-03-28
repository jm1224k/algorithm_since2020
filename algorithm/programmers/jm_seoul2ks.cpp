#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int K, vector<vector<int>> travel) {
	vector<int> d(100003);
	
	for (int i = 0; i < travel.size(); i++)
	{
		for (int j = K; j >= 0; j--)
        	{
			d[j] = INT_MIN;
            
			if (j >= travel[i][0])
				d[j] = max(d[j], d[j - travel[i][0]] + travel[i][1]);
			
            		if (j >= travel[i][2])
				d[j] = max(d[j], d[j - travel[i][2]] + travel[i][3]);
		}
	}
	return d[K];
}
