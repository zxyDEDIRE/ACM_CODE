/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int mod=998244353;
int mull(int a,int b)
{
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
void solve()
{
	int n,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(i==1)ans=x;
		else ans=(mull(ans,x)+ans+x)%mod;
	}
	cout<<ans<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1007 
给 n k r
n个数 分成k组 
每一组每个数之间差值大于r 问多少种分法

1 2 3 4 5
5 2 1 3 4 
*/