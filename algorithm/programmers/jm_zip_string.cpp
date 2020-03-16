#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int length = s.length();
	int answer = length;

	for (int i = 1; i <= length / 2; i++)
	{
		int ans = length;
		int zip = 1;
        	string sub = s.substr(0, i);

		for (int j = i; j < length; j += i)
		{
			if (j + i <= length)
			{
				string cur = s.substr(j, i);
				if (cur == sub)
					zip += 1;
				else
				{
					ans += (zip == 1) ? 0 : to_string(zip).length() - (zip - 1) * i;
					zip = 1;
					sub = cur;
				}
			}
		}
		ans += (zip == 1) ? 0 : to_string(zip).length() - (zip - 1) * i;

		if (ans < answer)
			answer = ans;
	}
	return answer;
}
