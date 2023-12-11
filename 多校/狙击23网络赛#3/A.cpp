#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
char ch[maxn];
ll p[maxn];
int n;
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	ll cnt_1=0;

	for(int i=1;i<=n;i++)
		if(ch[i]=='1')cnt_1++;

	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=(p[i-1]*2)%mod;	

	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}