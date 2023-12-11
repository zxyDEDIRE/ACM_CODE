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
const int maxn=4e6+100;
vector<int>v[maxn];
vector<pii>ans;
bool vis[maxn];
int p[maxn];
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		vis[i]=0;
	}
	ans.clear();
}
int dfs(int x,int fa)
{
	vis[x]=1;
	vector<int>p;
	if(x<=n)p.push_back(x);
	for(auto y:v[x])
	{
		if(vis[y])continue;
		int now=dfs(y,x);
		if(now!=0)
			p.push_back(now);
	}
	int len=p.size();
	reverse(p.begin(),p.end());
	int fl=0;
	if(len&1){
		fl=p.back();
		p.pop_back();
	}
	len=p.size();
	for(int i=0;i+1<len;i+=2)
	{
		int a=p[i];
		int b=p[i+1];
		ans.push_back({a,b});
	}
	return fl;
}
void solve()
{
	cin>>n;
	init();
	m=n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int a=i+p[i];
		int b=i-p[i];
		if(!mp.count(a))mp[a]=++m,vis[m]=0,v[m].clear();
		if(!mp.count(b))mp[b]=++m,vis[m]=0,v[m].clear();
		a=mp[a];
		b=mp[b];
		v[a].push_back(i);v[i].push_back(a);
		v[b].push_back(i);v[i].push_back(b);
	}
	int flag=1;
	for(int i=1;i<=m;i++)
		if(!vis[i]){
			int x=dfs(i,0);
			if(x!=0)flag=0;
		}
	if(flag){
		cout<<"Yes\n";
		for(auto [x,y]:ans)
			cout<<x<<" "<<y<<endl;
	}
	else{
		cout<<"No\n";
	}
	cout<<"->"<<endl;
	if((10)&&10);
	cout<<(1!=2)<<endl;

	// init();
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