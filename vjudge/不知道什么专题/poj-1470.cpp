/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e4;
int fa[maxn],dep[maxn],son[maxn],siz[maxn];
int top[maxn];
vector<int>v[maxn];
int in[maxn];
int p[maxn];
int n,m,s;
void dfs1(int x,int f,int deep)
{
	dep[x]=deep;
	siz[x]=1;
	fa[x]=f;
	son[x]=0;
	int maxson=-1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==f)continue;
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
	if(son[x])dfs2(son[x],topf);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int read() {
    int s = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
    return f ? -s : s;
}
void solve()
{

	{
		n=read();
		for(int i=1;i<=n;i++)
			v[i].clear(),p[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,t;
			x=read();
			t=read();
			for(int j=1;j<=t;j++)
			{
				y=read();
				v[x].push_back(y);
				in[y]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!in[i]){
				dfs1(i,i,1);
				dfs2(i,i);
				s=i;
				break;
			}
		}

		m=read();
		while(m--)
		{
			int x,y;
			x=read();
			y=read();
			int t=LCA(x,y);
			p[t]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(p[i])
			{
				printf("%d:%d\n",i,p[i]);
			}
		}
	}
}
signed main(){
	solve();
	return 0;
}