/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int out[maxn];
int in[maxn];
int n,m;
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
	if(dfn[x]==low[x])
	{
		int y;
		tot++;
		do{
			y=s.top();
			s.pop();
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
void init()
{
	memset(dfn+1,0,sizeof(int)*n);
	memset(low+1,0,sizeof(int)*n);
	memset(col+1,0,sizeof(int)*n);
	indx=tot=0;
	for(int i=1;i<=n;i++)
		v[i].clear();
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(auto y:v[i]){
			in[col[y]]++;
			out[col[i]]++;
		}
	int cnta=0,cntb=0;
	for(int i=1;i<=tot;i++)
	{
		if(!in[i])cnta++;
		if(!out[i])cntb++;
	}
	if(cnta==1&&cntb==1||tot==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}