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
vector<int>v[maxn],G[maxn];
int in[maxn],out[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
int num[maxn];
bitset<maxn>vis;
stack<int>s;
string str;
int n;
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
	cin>>n;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		int x=i+1;
		int y=x+1;
		if(str[i]=='=')
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
		else if(str[i]=='>')
		{
			v[y].push_back(x);
		}
		else if(str[i]=='<')
		{
			v[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]),in[col[y]]++;
	}
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(!in[i]){
			num[i]=1;
			q.push(i);
		}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:G[x])
		{
			num[y]=max(num[y],num[x]+1);
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<num[col[i]]<<" ";
	cout<<endl;
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