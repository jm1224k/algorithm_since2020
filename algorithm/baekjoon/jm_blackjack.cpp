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
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(v[i] + v[j] + v[k] <= m && v[i] + v[j] + v[k] > ret)
                    ret = v[i] + v[j] + v[k];
            }
        }
    }
    cout << ret << endl;
}
