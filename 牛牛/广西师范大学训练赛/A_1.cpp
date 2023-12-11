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
		}
		rt=t[rt][tmp];
		in[rt]++;
	}
}

long long dfs(int id,int x,int si)
{
	if(x==-1) return 0;
	long long ans=1e10;
	if(in[t[id][0]]){
		long long f=0;
		if(in[t[id][0]]!=si) f=1;
		ans=min(ans,dfs(t[id][0],x-1,in[t[id][0]])+(f<<x));
	}
	if(in[t[id][1]]){
		long long f=0;
		if(in[t[id][1]]!=si) f=1;
		ans=min(ans,dfs(t[id][1],x-1,in[t[id][1]])+(f<<x));
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		insert(p[i]);
	}
	// query();
	cout<<dfs(0,30,n)<<'\n';
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
01  10
10  00
11  01

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