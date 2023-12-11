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
struct Edge{
	int to,next,fl;
}edge[maxn];
int head[maxn],cnt;
int low[maxn],dfn[maxn],indx;
bitset<maxn>vis;
vector<pii>ans;
stack<int>s;
int n;
void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].fl=0;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init(){
	cnt=1;
	for(int i=1;i<=n;i++)
		head[i]=dfn[i]=low[i]=0;
	indx=0;
	ans.clear();
	vis.reset();
	while(!s.empty())
		s.pop();
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
				ans.push_back({min(x,y),max(x,y)});
		}
		else if(i!=(fa^1)&&dfn[y]<dfn[x]&&vis[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x])
	{ 
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
		}while(y!=x);
	}
}
void solve()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int x,y,k;char ch;
		cin>>x>>ch>>k>>ch;
		while(k--){
			cin>>y;
			if(x<y)
			{
				add(x+1,y+1);
				add(y+1,x+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" "<<dfn[i]<<" "<<low[i]<<endl;
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans.size()<<" critical links\n";
	for(auto [x,y]:ans)
		cout<<x-1<<" - "<<y-1<<"\n";
	cout<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n)
		solve();
	return 0;
}
/*
3 critical links
0 - 1
3 - 4
6 - 7


3 critical links
0 - 1
3 - 4
6 - 7

0 critical links

*/