#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

const int maxn=1111;
vector<int>v[maxn];
// dep深度 fa父亲 siz子树大小 son重儿子
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int top[maxn];//链首
int in[maxn];
int n,m,s;
void dfs1(int x,int f,int deep)
{
	dep[x]=deep;
	fa[x]=f;
	siz[x]=1;
	int maxson=-1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)//找重儿子
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(!son[x])return ;
	dfs2(son[x],topf);//首先找重链
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void solve()
{
	//n个点 m次询问 s为根节点
	cin>>n;
	for(int i=1;i<=n;i++){
		v[i].clear();
		son[i]=0;
		in[i]=0;
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0){
			s=i;
		}

	dfs1(s,0,1);
	dfs2(s,s);
	int x,y;
	cin>>x>>y;
	cout<<LCA(x,y)<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}