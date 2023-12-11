/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dep[maxn];
int p[maxn];
int n,q;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
void dfs1(int x,int a,int b)
{
	if(dep[x]==a)
		p[x]=b;
	for(auto y:v[x])
		if(dep[y]>dep[x])
			dfs1(y,a,b);
}
void dfs2(int x,int a,int b)
{
	if(dep[x]==a)
		p[x]+=b;
	for(auto y:v[x])
		if(dep[y]>dep[x])
			dfs2(y,a,b);
}
int dfs5(int x,int a)
{
	if(dep[x]==a) return p[x];
	int ans=0;
	for(auto y:v[x])
		if(dep[y]>dep[x])
			ans+=dfs5(y,a);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	cin>>q;
	while(q--)
	{
		int op,x,y,k;
		cin>>op;
		if(op==1)
		{
			cin>>x>>k;
			p[x]=k;
		}
		else if(op==2)
		{
			cin>>x>>y>>k;
			dfs1(x,dep[x]+y,k);
		}
		else if(op==3)
		{
			cin>>x>>y>>k;
			dfs2(x,dep[x]+y,k);
		}
		else if(op==4)
		{
			cin>>x;
			cout<<p[x]<<endl;
		}
		else if(op==5)
		{
			cin>>x>>y;
			cout<<dfs5(x,dep[x]+y)<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}