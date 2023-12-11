#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
int a[3];
void solve()
{
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]==1&&a[1]==a[2])puts("Lose");
	else if(a[0]==1||a[0]==a[1]||a[1]==a[2])puts("Win");
	else{
		if(a[0]+a[1]==a[2]+1)puts("Lose");
		else puts("Win");
	}
}
signed main()
{
	//IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}