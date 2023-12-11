/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int sum[maxn];
int p[maxn];
int n,q,k;
void solve()
{
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=2;i<n;i++)
	{
		int t=p[i+1]-1-p[i-1]-1;
		t=max(t,0);
		sum[i]=sum[i-1]+t;
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(l==r)cout<<k-1<<endl;
		else
		{
			ll ans=sum[r-1]-sum[l];
			ans+=p[l+1]-1;
			ans+=(k-p[r-1]-1);
			cout<<ans-1<<endl;
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}