#include<bits/stdc++.h>
using namespace std;

int n, m;
void solve()
{
	int r, c, v;
	cin >> r >> c >> v;
	int sum1 = r * c - 1;
	int sum2 = (n - r + 1) * (m - c + 1) - 1;
	if(sum1 <= v - 1 && sum2 <= (n * m) - v){
		cout << "Yes\n";
	}
	else cout << "No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin >> n >> m)
		solve(); 
	return 0;
}
