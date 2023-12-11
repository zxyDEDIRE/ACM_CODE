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
bitset<maxn>vis,vi,on;
int fa[maxn];
int n,q,fl,cnt;
void dfs1(int x)
{
	if(vis[x])
	{
		fl=1;
		return ;
	}
	if(x==1)
	{
		if(on[x]==1)vis[x]=1,fl=1;
		return ;
	}
	if(on[x]==0&&fl==1)return ;
	if(on[x]==1)fl=1;
	dfs1(fa[x]);
	if(fl)vis[x]=1;
}
void dfs2(int x)
{
	if(vi[x])
	{
		fl=1;
		return ;
	}
	if(x==1)
	{
		if(on[x]==1){
			vi[x]=1,fl=1;
			if(vis[x]==1)cnt++;
		}
		return ;
	}
	if(on[x]==0&&fl==1)return ;
	if(on[x]==1)fl=1;
	dfs2(fa[x]);
	if(fl)vi[x]=1;
	if(vi[x]==1&&vis[x]==1)cnt++;
}
void solve()
{
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		fa[i]=x;
	}
	while(q--)
	{
		vis.reset();
		vi.reset();
		on.reset();
		cnt=0;
		int x,y,z;
		cin>>x>>y>>z;
		vector<int>a(x+1),b(y+1),c(z+1);
		for(int i=0;i<x;i++)
			cin>>a[i];
		for(int i=0;i<y;i++)
			cin>>b[i];
		for(int i=0;i<z;i++){
			cin>>c[i];
			on[c[i]]=1;
		}
		for(int i=0;i<x;i++)
		{
			fl=0;
			dfs1(a[i]);
		}
		for(int i=0;i<y;i++)
		{
			fl=0;
			dfs2(b[i]);
		}
		cout<<cnt<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}