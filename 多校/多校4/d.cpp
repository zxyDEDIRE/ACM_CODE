/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
#include <random>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int seed;
int n,q;
ll fp(ll b,ll p)
{
	ll res=1;
	while(p){
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
int doit(int x,int y,int z)
{

	cout<<x<<" "<<y<<" "<<z<<endl;
	return 3;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		for(int j=1;j<=m;j++){
			int x;
			cin>>x>>x>>x;
		}
	}
	cin>>seed;

	std::mt19937 rng(seed);
	std::uniform_int_distribution<> u(1,400);

	ll ans=0;
	int lastans=0;
	for (int i=1;i<=q;i++)
	{
    	int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
    	int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
    	int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
    	lastans=doit(IQ,EQ,AQ);  // The answer to the i-th friend
    	ans+=lastans*fp(seed,q-i);
    	ans%=mod;
	}
	cout<<ans<<endl;
}
signed main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}