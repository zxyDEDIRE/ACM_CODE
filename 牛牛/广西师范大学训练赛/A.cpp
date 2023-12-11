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
int t[maxn][3],indx;
int in[maxn];
ll p[maxn];
ll ans=0;
int n;
void insert(ll x)
{
	int rt=0;
	for(int i=30;i>=0;i--)
	{
		int tmp=(x>>i)&1;
		if(!t[rt][tmp]){
			t[rt][tmp]=++indx;
			in[rt]++;
		}
		rt=t[rt][tmp];
	}
	// for(int i=1;i<=30;i++)
	// 	cout<<in[i]<<" ";cout<<endl;
}
void query()
{
	ll ans=0;
	int rt=0;
	for(int i=30;i>=0;i--)
	{
		// cout<<i<<" "<<rt<<" "<<in[rt]<<endl;
		if(in[rt]==1&&t[rt][0])
			rt=t[rt][0];
		else if(in[rt]==1&&t[rt][1])
		{
			rt=t[rt][1];
			ans|=(1ll<<i);
		}
		else if(in[rt]==2)
		{
			int x=in[t[rt][0]];
			int y=in[t[rt][1]];
			
			if(x==1)
			{
				ans|=(1ll<<i);
				rt=t[rt][0];
			}
			else 
			{
				rt=t[rt][1];
			}
		}
	}
	// cout<<ans<<endl;
	// cout<<endl;
	ll ma=0;
	for(int i=1;i<=n;i++)
	{
		// cout<<i<<" "<<p[i]<<" "<<(p[i]^ans)<<endl;
		ma=max(ma,(p[i]^ans));
	}
	cout<<ma<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		insert(p[i]);
	}
	query();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
01  10
10  00
11  01

11

01
10
11

4
0 1 2 3

1111
1010
0111
0100
0101



100
*/