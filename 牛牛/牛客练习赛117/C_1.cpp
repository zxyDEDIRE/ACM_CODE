#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int n,m,k;
bool check(int a,int b)
{
	if(k==1&&b)return 0;
	if(k==1)return 1;
	int ds = k/2;
	int x=b/ds;

	if(k&1)a-=x;
	if(a<0)return 0;

	b-=x*ds;
	
	if(b)a-=(k-2*b);
	if(a<0)return 0;
	if(a%k==0)return 1;
	return 0;
}
bool ok(int x)
{
	for(int j=0;j<(1ll<<x);j++)
	{
		int _x=n,_y=m;
		for(int i=0;i<x;i++)
			if(j&(1<<i))_x--;
			else _y--;
		if(_x<0||_y<0)return 0;
		if(check(_x,_y))return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m>>k;
	int ans=INF;
	// cout<<check(n,m)<<endl;
	if(check(n,m)){
		cout<<0<<endl;
		return ;
	}
	for(int i=1;i<=min(10*1ll,n+m);i++)
		if(ok(i))ans=min(ans,i);
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
2
2
11
1


1
3 3 2
*/