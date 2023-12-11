/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dep[maxn][2],fa[maxn][2],son[maxn][2],siz[maxn][2];
int top[maxn][2];
vector<int>v[2][maxn];
int a[maxn],b[maxn];
int pa[maxn],pb[maxn];
int sa[maxn],sb[maxn];
int p[maxn];
int n,k;
void dfs1(int x,int faa,int deep,int fl)
{
	dep[x][fl]=deep;
	fa[x][fl]=faa;
	siz[x][fl]=1;
	int maxson=-1;
	for(auto y:v[fl][x])
	{
		if(y==faa)continue;
		dfs1(y,x,deep+1,fl);
		siz[x][fl]+=siz[y][fl];
		if(siz[x][fl]>maxson)
		{
			maxson=siz[y][fl];
			son[x][fl]=y;
		}
	}
}
void dfs2(int x,int topf,int fl)
{
	top[x][fl]=topf;
	if(son[x][fl])dfs2(son[x][fl],topf,fl);
	for(auto y:v[fl][x])
	{
		if(y==fa[x][fl]||y==son[x][fl])continue;
		dfs2(y,y,fl);
	}
}
int LCA(int x,int y,int fl)
{
	while(top[x][fl]!=top[y][fl])//不同链
	{
		if(dep[top[x][fl]][fl]<dep[top[y][fl]][fl])swap(x,y);
		x=fa[top[x][fl]][fl];
	}
	if(dep[x][fl]>dep[y][fl])swap(x,y);
	return x;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		v[0][i].push_back(x);
		v[0][x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		v[1][i].push_back(x);
		v[1][x].push_back(i);
	}
	dfs1(1,1,0,0);
	dfs1(1,1,0,1);
	dfs2(1,1,0);
	dfs2(1,1,1);
	int fa,fb;
	pa[1]=p[1];
	pb[1]=p[1];
	for(int i=2;i<=k;i++)
	{
		pa[i]=LCA(pa[i-1],p[i],0);
		pb[i]=LCA(pb[i-1],p[i],1);
	}
	sa[k]=sb[k]=p[k];
	for(int i=k-1;i>=1;i--)
	{
		sa[i]=LCA(sa[i+1],p[i],0);
		sb[i]=LCA(sb[i+1],p[i],1);
	}
	int ans=0;
	for(int i=2;i<k;i++)
	{
		int x=LCA(pa[i-1],sa[i+1],0);
		int y=LCA(pb[i-1],sb[i+1],1);
		if(a[x]>b[y])ans++;
	}
	if(a[sa[2]]>b[sb[2]])ans++;
	if(a[pa[k-1]]>b[pb[k-1]])ans++;
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}