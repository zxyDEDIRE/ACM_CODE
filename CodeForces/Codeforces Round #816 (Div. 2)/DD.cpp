/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e5+100;
struct node{
	int x,y,w;
}p[maxn];
int low[maxn],dfn[maxn],indx;
int col[maxn],tot;
vector<int>v[maxn];
bitset<maxn>vis;
int ans[maxn];
stack<int>s;
int n,m,ma;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		++tot;
		int y;
		do{
			y=s.top();
			s.pop();
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].x>>p[i].y>>p[i].w,ma=max(ma,p[i].w);
	for(int j=0;j<30;j++)
	{
		for(int i=1;i<=n*2;i++)
			v[i].clear(),dfn[i]=0;
		indx=tot=0;

		for(int i=1;i<=m;i++)
		{
			auto [x,y,w]=p[i];
			if(w&(1<<j))
			{
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else
			{
				v[x+n].push_back(x);
				v[y+n].push_back(y);
				v[x].push_back(y);
				v[y].push_back(x);
			}
		}

		for(int i=1;i<=n*2;i++)
			if(!dfn[i])
				tarjan(i);

		for(int i=1;i<=n;i++)
			if(col[i]>col[i+n])
				ans[i]+=(1<<j);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Us
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}