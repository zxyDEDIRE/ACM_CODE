#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
// dep深度 fa父亲 siz子树大小 son重儿子
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int top[maxn];//链首
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
bool doit(int a,int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		if(top[a]==top[x]&&dep[a]<=dep[x]){
			return 1;
		}
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(top[a]==top[x]&&dep[a]>=dep[x]&&dep[a]<=dep[y]){
		return 1;
	}
	return 0;
}
void solve()
{
	//n个点 m次询问 s为根节点
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	s=1;
	dfs1(s,0,1);
	dfs2(s,s);
	while(m--){
		int x,y;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		x=LCA(a,b);
		y=LCA(c,d);
		bool res=0;
		res|=doit(x,c,d);
		res|=doit(y,a,b);
		if(res)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}