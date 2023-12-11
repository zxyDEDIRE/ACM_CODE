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
	int l,r;
}p[maxn];
vector<int>v[maxn];
int fa[maxn];
int in[maxn];
char ch[maxn];
int ans;
int n;
void dfs(int x,int num)
{
	auto [l,r]=p[x];
	if(l==0&&r==0)
	{
		ans=min(ans,num);
		return ;
	}
	if(l!=0)
	{
		int w=1;
		if(ch[x]=='L')w=0;
		dfs(l,num+w);
	}
	if(r!=0)
	{
		int w=1;
		if(ch[x]=='R')w=0;
		dfs(r,num+w);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		v[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		auto &[l,r]=p[i];
		cin>>l>>r;
	}
	ans=INF;
	dfs(1,0);
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