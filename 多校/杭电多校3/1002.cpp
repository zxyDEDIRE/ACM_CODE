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
vector<int>v[20];
ll t[20],len[20];
ll n,H,l,r,sum;
bool check(ll k)
{
	for(int I=0;I<(1<<n);I++)
	{

	}
}
void solve()
{
	cin>>n>>H;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>len[i];r+=t[i]+len[i];
		for(int j=1;j<=len[i];j++)
		{
			int x;cin>>x;
			sum+=x;
			v[i].push_back(x);
		}
	}
	if(sum<H){
		cout<<-1<<endl;
		return ;
	}
	l=1;
	ll ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;


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