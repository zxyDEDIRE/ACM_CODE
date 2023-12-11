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
const int maxn=1e6;
vector<int>v[maxn];
int fa[maxn],siz[maxn],dep[maxn],son[maxn];
int top[maxn],id[maxn],tot;
int p[maxn];
int n,m,q;
void dfs1(int x,int faa,int deep)
{
	siz[x]=1;
	fa[x]=faa;
	dep[x]=deep;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==faa)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int lca(int x,int y)
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
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1,0);
	dfs2(1,1);
	cin>>q;
	while(q--)
	{
		int s=0,t=0;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			if(dep[p[i]]>dep[s])s=p[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(p[i]!=s&&dep[p[i]]>dep[t]&&lca(s,p[i])!=p[i])t=p[i];
		}
		//cout<<s<<" "<<t<<endl;
		if(s&&t)
		{
			int topf=lca(s,t);
			int flag=1;
			//cout<<topf<<endl;
			for(int i=1;i<=m;i++)
			{
				if(p[i]==s||p[i]==t)continue;
				int x=lca(s,p[i]);
				int y=lca(t,p[i]);
				if((x==p[i]&&y==topf)||(y==p[i]&&x==topf));
				else flag=0;
			}
			if(flag)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}