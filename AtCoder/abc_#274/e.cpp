/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,mp;
	bool operator<(const node a)const{
		if(a.x!=x)return a.x<x;
		else return a.mp<mp;
	}
};
double mpp[maxn][20];
bitset<1000>vis;
pii p[100];
pii q[100];
double res=1e18;
int n,m,st;
double f(int x,int y)
{
	return 1.0*sqrt(
		(p[x].first-p[y].first)*
		(p[x].first-p[y].first)+
		(p[x].second-p[y].second)*
		(p[x].second-p[y].second)
	);

	//hypot(p[x].first-p[y].first,p[x].second-p[y].second);
}
void dfs(int x,int mp=0,double t=1,double ans=0.0)
{
	if(ans>res)return ;
	if(((mp&st)&st)==st)
	{
		ans+=1.0*f(x,0)/t;
		res=min(res,ans);
		return ;
	}
	for(int i=1;i<=n+m;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		int mp_1=mp,t_1=t;
		mp_1|=(1ll<<(i-1));
		if(mpp[mp_1][i]<mpp[mp][x]+1.0*f(x,i)/t)continue;
		mpp[mp_1][i]=mpp[mp][x]+1.0*f(x,i)/t;
		if(i>n)t_1*=2;
		dfs(i,mp_1,t_1,ans+1.0*f(x,i)/t);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>m;
	st=((1ll<<n)-1);
	p[0].first=0;p[0].second=0;
	for(int i=0;i<1<<n+m;i++)
		for(int j=1;j<=n+m;j++)
			mpp[i][j]=1e18;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=n+1;i<=m+n;i++)
		cin>>p[i].first>>p[i].second;
	dfs(0);
	printf("%.7lf\n",res);
}
signed main(){
	// int mp=15;
	// int st=3;
	// cout<<(mp&st)<<endl;
	// cout<<((mp&st)&st);
	// return 0;
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);8421
//  fclose(stdout);
	return 0;
}
/*
7 2
4 4
1 0
0 1
9 0
1 9
9 9
12 14
10 10
10 0



*/