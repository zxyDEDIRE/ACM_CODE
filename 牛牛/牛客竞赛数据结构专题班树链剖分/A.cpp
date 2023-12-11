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
const int mod=201314;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int n,q;
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
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void solve()
{
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		v[x+1].push_back(i);
	}
	dfs1(1,1,0);
	dfs2(1,1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}