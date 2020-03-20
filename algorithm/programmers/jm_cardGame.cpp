#include <vector>
#include <algorithm>

using namespace std;

int d[2001][2001];

int size;
vector<int> L;
vector<int> R;

int dp(int l, int r)
{
    if(l == size || r == size)
        return 0;
    
    if(d[l][r] > 0)
        return d[l][r];
    
    d[l][r] = max(dp(l+1, r), dp(l+1, r+1));
    
    if(L[l] > R[r])
    {
        d[l][r] = max(d[l][r], dp(l, r+1) + R[r]);
    }
    
    return d[l][r];
}

int solution(vector<int> left, vector<int> right) {
    
    size = left.size();
    L = left;
    R = right;
    
    return dp(0, 0);
}
