/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
p(2) p[maxn];
int a[maxn];
int b[maxn];
int n,m;
void init()
{
	for(int i=1;i<=n*2;i++)
		dfn[i]=low[i]=vis[i]=0,v[i].clear();
	indx=tot=0;
}
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
		tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
bool check(int mid)
{
	init();
	for(int i=1;i<=m;i++)
	{
		int x=p[i][0];
		int y=p[i][1];
		int cnt=0;
		if(abs(a[x]-a[y])>mid)
		{
			v[x].push_back(y+n);
			v[y].push_back(x+n);
			cnt++;
		}
		if(abs(b[x]-b[y])>mid)
		{
			v[x+n].push_back(y);
			v[y+n].push_back(x);
			cnt++;
		}
		if(abs(a[x]-b[y])>mid)
		{
			v[x].push_back(y);
			v[y+n].push_back(x+n);
			cnt++;
		}
		if(abs(b[x]-a[y])>mid)
		{
			v[x+n].push_back(y+n);
			v[y].push_back(x);
			cnt++;
		}
		if(cnt==4)return 0;
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(col[i]==col[i+n])
			return 0;
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		cin>>p[i][0]>>p[i][1];
	// cout<<check(2)<<endl;
	int l=0,r=1e9+10,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
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