/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<ll>x,y;
ll n,m,q;
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		if(v==0||v==n)x.push_back(u);
		if(u==0||u==m)y.push_back(v);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ll ans=0;
	for(int i=0;i<x.size()-1;i++)
		ans=max(ans,(x[i+1]-x[i])*n);
	for(int i=0;i<y.size()-1;i++)
		ans=max(ans,(y[i+1]-y[i])*m);


	cout<<ans<<endl;

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}