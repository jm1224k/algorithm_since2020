#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //input
    int n, answer, r1, r2;
    vector<pair <int, int>> line;
    vector<int> dp;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> r1 >> r2;
        line.push_back(make_pair(r1, r2));
    }

    //solve
    sort(line.begin(), line.end());
    
    for(int i = 0; i < n; i++)
        dp.push_back(1);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(line[i].second > line[j].second)
                if(dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
        }
        answer = max(dp[i], answer);
    }

    //output
    cout << n - answer << endl;
}
