/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int n,m,k;
void solve()
{
	int ans=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int x=n/(i+1);
		int y=(k+x-1)/x;
		if(m/y-1<0)continue;
		//cout<<x<<" "<<y<<" "<<i<<" "<<m/y-1<<" "<<i+m/y-1<<endl;
		ans=max(ans,i+m/y-1);
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}