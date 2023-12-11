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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int f[maxn][30];
int dep[maxn];
int n,m,l=-1,r=-1,ma,q;
void dfs1(int x,int fa,int deep)
{
	l=deep>ma?x:l;
	ma=max(ma,deep);
	for(auto y:v[x])
		if(y!=fa)
			dfs1(y,x,deep+1);
}
void dfs2(int x,int fa,int deep)
{
	r=deep>ma?x:r;
	ma=max(ma,deep);
	for(auto y:v[x])
		if(y!=fa)
			dfs2(y,x,deep+1);
}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int k=1;k<=20;k++)
		f[x][k]=f[f[x][k-1]][k-1];
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int k=20;k>=0;k--)
		if(dep[f[x][k]]>=dep[y])
			x=f[x][k];
	if(x==y)return x;
	for(int k=20;k>=0;k--)
		if(f[x][k]!=f[y][k])
			x=f[x][k],y=f[y][k];
	return f[x][0];
}
int dis(int x,int y)
{
	int z=LCA(x,y);
	int ans=0;
	ans+=dep[x]-dep[z];
	ans+=dep[y]-dep[z];
	return ans;
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
	ma=0;dfs1(1,0,1);
	ma=0;dfs2(l,0,1);
	dfs(1,0);



	cin>>q;
	while(q--)
	{
		int x,y,k;
		cin>>x>>k;
		int disa=dis(x,l);
		int disb=dis(x,r);

		if(disa>=disb)y=l;
		else y=r;

		if(k>max(disa,disb))cout<<-1<<endl;
		else
		{
			if(dep[x]-dep[LCA(x,y)]>=k)
			{
				for(int i=20;i>=0;i--)
					if(k>=(1<<i)){
						k-=(1<<i);
						x=f[x][i];
					}
				cout<<x<<endl;
			}
			else
			{
				k=dis(x,y)-k;
				swap(x,y);
				for(int i=20;i>=0;i--)
					if(k>=(1<<i)){
						k-=(1<<i);
						x=f[x][i];
					}
				cout<<x<<endl;
			}
		}
	}
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
/*
5
1 2
2 3
3 4
3 5
1
2 2
*/