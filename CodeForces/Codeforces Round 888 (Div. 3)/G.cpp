/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct node{
	int a,b,e,i;
}t[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int ans[maxn];
int f[maxn];
int h[maxn];
int b[maxn];
int n,m,q;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		f[i]=i;
		b[i]=i;
		v[i].clear();
		ans[i]=0;
	}
	vis.reset();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int x,y,e;
		cin>>x>>y>>e;
		e+=h[x];
		t[i]={x,y,e,i};
	}
	sort(t+1,t+1+q,[&](node a,node b){
		return a.e<b.e;
	});
	sort(b+1,b+1+n,[&](int a,int b){
		return h[a]<h[b];
	});
	int now=1;
	for(int i=1;i<=q;i++)
	{
		auto [x,y,e,id]=t[i];
		while(now<=n&&h[b[now]]<=e)
		{
			int u=b[now];
			vis[u]=1;
			for(auto v:v[u])
			{
				if(!vis[v])continue;
				int fa=find(u);
				int fb=find(v);
				if(fa!=fb)f[fa]=fb;
			}
			now++;
		}
		int fa=find(x);
		int fb=find(y);
		if(fa==fb)ans[id]=1;
		// else ans[id]=0;
	}
	for(int i=1;i<=q;i++)
		if(ans[i]==1)cout<<"YES\n";
		else cout<<"NO\n";
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}