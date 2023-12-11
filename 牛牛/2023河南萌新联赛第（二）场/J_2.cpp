#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int maxn=1e6+1000;
const int M=1e6;
int INF[maxn];
int F[maxn];
string str;
int n,m;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int mull(int a,int b){
	return (a*b)%mod;
}
void init()
{
	F[0]=INF[0]=1;
	for(int i=1;i<=M;i++)
	{
		F[i]=(F[i-1]*i)%mod;
		INF[i]=ksm(F[i],mod-2);
	}
}
int C(int n,int m)
{
	if(n==m)return 1;
	if(n==0)return 0;
	if(m>n)return 0;
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;
}
void solve()
{
	cin>>n>>m>>str;
	int num_0=0,num_1=0;
	for(auto i:str)
		if(i=='0')num_0++;
		else num_1++;
	int tot=C(n,num_0);
	int ans=0;
	if(m&1)
	{
		ans=(ans+mull(C(num_0-1,m/2-1),C(num_1-1,m/2) ))%mod;
		ans=(ans+mull(C(num_0-1,m/2),C(num_1-1,m/2-1) ))%mod;
	}
	else
	{
		int ans_1=C(num_0-1,m/2-1);
		int ans_2=C(num_1-1,m/2-1);
		ans=(ans+mull(ans_1,ans_2)*2)%mod;
	}
	cout<<ans<<" "<<(tot+mod-ans)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	solve();
	return 0;
}