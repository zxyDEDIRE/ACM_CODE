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
int dep[maxn],fa[maxn],siz[maxn],son[maxn],top[maxn];
ll a[maxn],b[maxn];
vector<int>v[maxn];
int n;
inline void dfs1(int x,int f,int deep)//当前点，父亲点，深度
{
	dep[x]=deep;	//记录每个点的深度
	fa[x]=f;	//记录每个点的父亲
	siz[x]=1;	//记录每个点子树大小
	int maxson=-1;	//记录重儿子的儿子树 要计较
	for(auto y:v[x])
	{
		if(y==f)continue;
		a[y]+=a[x];
		b[y]+=b[x];
		dfs1(y,x,deep+1);	//遍历儿子
		siz[x]+=siz[y];	//加上子树大小
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//记录比较重儿子
	}
}
inline void dfs2(int x,int topf)//当前节点，topf当前链的链首
{
	top[x]=topf;	//当前点的链首
	if(!son[x])return ;	//没有儿子
	dfs2(son[x],topf);	//先处理重儿子，在处理轻儿子
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);//新建重链
	}
}
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++)
		a[i]=b[i]=son[i]=0,v[i].clear();
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x>>a[i]>>b[i];
		v[x].push_back(i);
	}
	dfs1(1,1,0);
	dfs2(1,1);

	for(int i=2;i<=n;i++)
	{
		ll ans=a[i];
		int x=i,y;
		while(b[x]>ans)
		{
			y=fa[top[x]];
			if(b[y]>=ans)x=y;
			else x=fa[x];
		}
		cout<<dep[x]<<" ";
	}
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
9
1 5 6
4 5 1
2 9 10
4 2 1
1 2 1
2 3 3
6 4 3
8 1 3
*/