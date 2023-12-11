#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y,w;
}p[maxn];
int num[maxn];
int f[maxn];
ll n,s;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)f[i]=i,num[i]=1;
	for(int i=1;i<n;i++)
	{
		auto &[x,y,w]=p[i];
		cin>>x>>y>>w;
	}
	sort(p+1,p+n,[&](node a,node b){
		return a.w<b.w;
	});
	ll ans=1;
	for(int i=1;i<n;i++)
	{
		auto [x,y,w]=p[i];
		int fa=find(x);
		int fb=find(y);
		f[fa]=fb;
		ans*=ksm(s-w+1,1ll*num[fa]*num[fb]-1);
		ans%=mod;
		num[fb]+=num[fa];
	}
	cout<<ans<<endl;


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
5 6
3 5 1
1 3 2
1 2 3
3 4 6
*/