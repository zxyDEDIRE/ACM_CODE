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
const int maxn=3e6+100;
vector<int>v[maxn];
int low[maxn],dfn[maxn],col[maxn],tot,indx;
bitset<maxn>vis;
stack<int>s;
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
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,a,y,b;
		cin>>x>>a>>y>>b;
		if(a==1&&b==1)
		{
			v[x].push_back(y+n);
			v[y].push_back(x+n);
		}
		else if(a==0&&b==1)
		{
			v[x+n].push_back(y+n);
			v[y].push_back(x);
		}
		else if(a==1&&b==0)
		{
			v[x].push_back(y);
			v[y+n].push_back(x+n);
		}
		else if(a==0&&b==0)
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
			cout<<"IMPOSSIBLE"<<endl;
			return ;
		}
	cout<<"POSSIBLE"<<endl;
	for(int i=1;i<=n;i++)
		cout<<(col[i]>col[i+n])<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4782_1.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}