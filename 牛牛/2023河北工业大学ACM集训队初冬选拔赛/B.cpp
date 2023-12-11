#include<bits/stdc++.h>
using namespace std;
// #define endl "\n"
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
const int N=2011;
struct node{
	int l,r;bool op;
	bool operator!=(node a)const{
		if(l!=a.l)return 1;
		if(r!=a.r)return 1;
		if(op!=a.op)return 1;
		return 0;
	}
	bool operator==(node a)const{
		if(l==a.l&&r==a.r&&op==a.op)return 1;
		return 0;
	}
}T;
bool ok[maxn];
int p[maxn];
node dp[N][N];
int n;
node dfs(int l,int r)
{
	if(l>r)return T;
	if(dp[l][r]!=T)return dp[l][r];
	if(l==r)return dp[l][r]={p[l]-1,p[r]+1,1};
	// cout<<l<<" "<<r<<endl;
	// _sleep(100);
	dp[l][r]={-1,-1,0};

	node now=dfs(l+1,r);
	if(p[l]+2==now.l && now.op==1)
	{
		dp[l][r].l=p[l]-1;
		dp[l][r].r=now.r;
		dp[l][r].op=1;
	}

	now=dfs(l,r-1);
	if(now.r+1==p[l]-1 && now.op==1)
	{
		dp[l][r].l=now.l;
		dp[l][r].r=p[l]+1;
		dp[l][r].op=1;
	}

	// for(int i=l+1;i<r;i++)
	// {
	// 	if(l>i-1)continue;
	// 	if(i+1>r)continue;

	// 	auto x=dfs(l,i-1);
	// 	int _l=p[i]-1;
	// 	int _r=p[i]+1;
	// 	auto y=dfs(i+1,r);
	// 	if(x.op==1 && y.op==1 && x.r==_l+1&&_r+1==y.l)
	// 	{
	// 		dp[l][r].l=x.l;
	// 		dp[l][r].r=y.r;
	// 		dp[l][r].op=1;
	// 		break;
	// 	}
	// }

	return dp[l][r];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		p[n+i]=p[i];
	}
	dfs(3,4);
	auto x = dp[3][3];
	cout<<x.l<<" "<<x.r<<" "<<x.op<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}