#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0, tmp = 0, answer = -1;
    vector<int> v[500];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            scanf("%d", &tmp);
            v[i].push_back(tmp);
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(j == 0)
                v[i][j] += v[i - 1][0];
            else if(j == v[i].size() - 1)
                v[i][j] += v[i - 1][j - 1];
            else
                v[i][j] += v[i - 1][j - 1] < v[i - 1][j] ? v[i - 1][j] : v[i - 1][j - 1];
        }
    }
    
    for(int i = 0; i < v[n - 1].size(); i++)
    {
        if(answer == -1 || answer < v[n - 1][i])
            answer = v[n - 1][i];
    }

    printf("%d\n", answer);

    return 0;
}
