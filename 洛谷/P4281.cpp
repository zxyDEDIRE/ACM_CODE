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
int siz[maxn],fa[maxn],dep[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
vector<int>v[maxn];
int n,m;
void dfs1(int x,int f,int deep)
{
	siz[x]=1;
	dep[x]=deep;
	fa[x]=f;
	int maxson=-1;
	for(auto y:v[x])
	{
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
	for(auto y:v[x])
	{
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
int dis(int x,int y)
{
	int rt=LCA(x,y);
	return dep[x]+dep[y]-dep[rt]*2;
}
pii f(int a,int b,int c)
{
	int rt=LCA(a,b);
	int w=dis(a,rt)+dis(b,rt)+dis(c,rt);
	return {rt,w};
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1,0);
	dfs2(1,1);
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		pii x=f(a,b,c);
		pii y=f(a,c,b);
		pii z=f(b,c,a);
		int mi=min({x.second,y.second,z.second});
		if(mi==x.second)cout<<x.first<<" "<<mi<<endl;
		else if(mi==y.second)cout<<y.first<<" "<<mi<<endl;
		else cout<<z.first<<" "<<mi<<endl;
	}
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
/*
*/