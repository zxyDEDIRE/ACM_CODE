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
const int maxn=2e2+100;
vector<int>v[maxn],G[maxn];
int a[maxn],b[maxn];
bitset<maxn>vis;
int in[maxn];
int n,m,flag=0;
void init(){
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		G[i].clear();
		a[i]=b[i]=in[i]=0;
	}
	flag=0;
}
void dfs1(int x,int s){
	if(vis[x])return ;
	vis[x]=1;
	a[s]++;
	for(auto y:G[x])
		dfs1(y,s);
}
void dfs2(int x,int s){
	if(vis[x])return ;
	vis[x]=1;
	b[s]++;
	for(auto y:v[x])
		dfs2(y,s);
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		G[y].push_back(x);
		if(x==y)flag=1;
		in[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		vis.reset();
		dfs1(i,i);
		vis.reset();
		dfs2(i,i);
		a[i]--;b[i]--;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto y:v[x]){
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(in[i])flag=1;
	if(flag){
		for(int i=1;i<=n;i++)
			cout<<"0";
		cout<<endl;
		return ;
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" \n"[i==n];
	int mid=(1+n)/2;
	for(int i=1;i<=n;i++)
		if(a[i]<mid&&b[i]<mid)cout<<"1";
		else cout<<"0";
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
5 2
1 2
3 4
*/