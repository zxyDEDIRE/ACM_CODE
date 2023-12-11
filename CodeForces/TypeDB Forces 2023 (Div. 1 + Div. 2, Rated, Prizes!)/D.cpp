/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
int low[maxn],dfn[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
stack<int>s;
int a[maxn];
int n,ans,sum;
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
			num[tot]++;
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
void dfs(int x,int cnt)
{
	if(vis[x])return ;
	vis[x]=1;
	int now=sum;
	if(num[col[x]]>1||a[x]==0)now-=num[col[x]];
	// cout<<sum<<" "<<now<<endl;
	now+=cnt;
	ans+=n-now-1;
	ans+=n-x+1;
	ans+=x;
	// cout<<x<<" "<<n-now-1<<" "<<n-x+1<<" "<<x<<endl;
	if(v[x].size())
		dfs(v[x][0],cnt+1);
}
void solve()
{
	cin>>n;
	indx=0;
	for(int i=1;i<=n;i++)
	{
		dfn[i]=0;
		num[i]=0;
		v[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i+a[i]>=1&&i+a[i]<=n)
			v[i].push_back(i+a[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	sum=0;
	for(int i=1;i<=n;i++)
		if(num[col[i]]>1||a[i]==0)
			sum++;
	dfs(1,0);
	cout<<ans<<endl;
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