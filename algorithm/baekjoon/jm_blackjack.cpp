#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m, ret;
    vector<int> v;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> ret;
        v.push_back(ret);
    }

    ret = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;

            for(int k = 0; k < n; k++)
            {
                if(j == k || i == k)
                    continue;
                
                if(v[i] + v[j] + v[k] <= m && v[i] + v[j] + v[k] > ret)
                    ret = v[i] + v[j] + v[k];
            }
        }
    }

    cout << ret << endl;
}
