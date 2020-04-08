#include <iostream>
#include <vector>

using namespace std;

vector<pair <int, int> > v;

void hanoi(int N, int start, int end, int via)
{
    if(N == 1)
        v.push_back(make_pair(start, end));
    else
    {
        hanoi(N-1, start, via, end);
        v.push_back(make_pair(start, end));
        hanoi(N-1, via, end, start);
    }
}
 
int main(void)
{
	int n;
	cin >> n;
    
	hanoi(n, 1, 3, 2);
    
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
 
	return 0;
}
