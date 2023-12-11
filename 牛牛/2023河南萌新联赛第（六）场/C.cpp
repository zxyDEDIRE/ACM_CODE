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
vector<int>v[maxn];
int siz[maxn];
int dp[maxn];
double ma=0;
int n,tot;
void dfs(int x,int fa=0)
{
	if(v[x].size()==1)siz[x]=1;
	for(auto y:v[x])
		if(y!=fa){
			dfs(y,x);
			siz[x]+=siz[y];
			dp[x]+=siz[y]+dp[y];
		}
}
void dfs1(int x,int fa,int sum)
{
	cout<<x<<" "<<sum<<" ";
	if(v[x].size()==1){
		cout<<1.0*sum/(tot-1)<<endl;
		ma=max(ma,1.0*sum/(tot-1));
	}
	else{
		cout<<1.0*sum/tot<<endl;
		ma=max(ma,1.0*sum/tot);
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		int now=sum;
		now=now-siz[y]+(tot-siz[y]);
		dfs1(y,x,now);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int root=0;
	for(int i=1;i<=n;i++)
		if(v[i].size()>1){
			root=i;
			break;
		}
	cout<<"root "<<root<<endl;
	dfs(root);
	tot=siz[root];
	cout<<"tot "<<tot<<endl;
	cout<<"sum "<<dp[root]<<endl;
	cout<<endl;
	ma=max(ma,1.0*dp[root]/siz[root]);
	dfs1(root,0,dp[root]);
	cout<<ma<<endl;
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
9
1 2
1 3
1 4
2 5
5 8
5 9
3 6
4 7
*/