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
vector<int>v[111];
ll a[maxn];
ll p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=0;i<=100;i++)
	{
		a[i]=0;
		v[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		ll x=log2(p[i]);
		while(x&&p[i]%(1<<x)!=0)
		{
			x--;
		}
		if(p[i]%(1<<x)==0)
		v[x].push_back(i);
	}
	int now=INF;
	while(q--)
	{
		ll k;
		cin>>k;
		if(k<now)
		{
			a[k]++;
			now=k;
		}
	}
	ll T=0;
	for(int i=1;i<=30;i++)
	{
		if(a[i])
			T+=(1ll<<(i-1));
		for(auto x:v[i])
			p[x]+=T;
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
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
1
5 3
1 2 4 8 16
5 2 1
*/