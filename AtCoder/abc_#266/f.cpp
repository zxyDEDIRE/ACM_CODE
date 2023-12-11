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
int low[maxn],dfn[maxn],indx;
vector<int>v[maxn];
bitset<maxn>cut;
stack<int>s;
int p[maxn];
int n,root;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	int flag=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		int y;
		int num;
		do{
			y=s.top();s.pop();
			num++;
		}while(x!=y);
		if(num==1)cut[x]=1;
	}
}
void dfs(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		int fa=find(x);
		int fb=find(y);
		p[fa]=fb;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		if(!dfn[i]){
			root=i;
			tarjan(i,i);
		}
	for(int i=1;i<=n;i++)
	{
		if(cut[i])continue;
		for(auto y:v[i])
		{
			if(cut[y]){
				int fa=find(y);
				int fb=find(i);
				p[fa]=fb;
				dfs(y,i);
			}
		}
	}

	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		if(fa==fb)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4
1 2
2 3
3 1
3 4
*/