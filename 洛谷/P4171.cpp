/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
stack<int>s;
int n,m;
void init()
{
	indx=tot=0;
	for(int i=1;i<=n*2;i++)
		v[i].clear(),dfn[i]=0;
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
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		char chx,chy;
		int x,y,fa=0,fb=0;
		getchar();scanf("%c%d",&chx,&x);
		getchar();scanf("%c%d",&chy,&y);
		if(chx=='m')fa=1;
		if(chy=='m')fb=1;
		if(fa&&fb)
		{
			v[x].push_back(y+n);
			v[y].push_back(x+n);
		}
		else if(!fa&&fb)
		{
			v[x+n].push_back(y+n);
			v[y].push_back(x);
		}
		else if(fa&&!fb)
		{
			v[x].push_back(y);
			v[y+n].push_back(x+n);
		}
		else if(!fa&&!fb)
		{
			v[x+n].push_back(y);
			v[y+n].push_back(x);
		}
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(col[i]==col[i+n]){
			cout<<"BAD"<<endl;
			return ;
		}
	cout<<"GOOD"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 4
m3 h1
m1 m2
h1 h3
h3 m2
*/