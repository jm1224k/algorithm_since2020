#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    //input
    int answer = 0, i, j;
    string a, b;

    cin >> a >> b;
    int len1 = a.size();
    int len2 = b.size();

    int dp[len1 + 1][len2 + 1];
    for (i = 0; i <= len1; i++)
        for (j = 0; j <= len2; j++)
            dp[i][j] = 0;

    //solve
    for(i = 1; i <= a.size(); i++)
    {
        for(j = 1; j <= b.size(); j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
        }
    }

    //output
    cout << dp[len1][len2] << endl;
}
