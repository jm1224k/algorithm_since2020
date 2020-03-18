#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	vector<pair <int, string>> orders;
	vector<pair <int, int>> temp;

	for (int i = 0; i < genres.size(); i++)
	{
		int j = 0;
		for (; j < orders.size(); j++)
		{
			if (orders[j].second == genres[i])
			{
				orders[j].first += plays[i];
				break;
			}
		}
		if (j == orders.size())
			orders.push_back(make_pair(plays[i], genres[i]));
	}

	sort(orders.begin(), orders.end(), greater<pair<int, string>>());

	for (int i = 0; i < orders.size(); i++)
	{
		for (int j = 0; j < genres.size(); j++)
		{
			if (genres[j] == orders[i].second)
			{
				temp.push_back(make_pair(plays[j], j));
			}
		}

		sort(temp.begin(), temp.end(),
			[](pair<int, int> a, pair<int, int> b)
		{
			if (a.first == b.second)
				return a.second < b.second;
			else
				return a.first > b.first;
		});

		if (temp.size() > 1)
		{
			answer.push_back(temp[0].second);
			answer.push_back(temp[1].second);
		}
		else
			answer.push_back(temp[0].second);
        
    temp.clear();
	}
	return answer;
}
