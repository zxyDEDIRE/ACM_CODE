/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
struct node{
	int fa,sum;
	int ma,l_ma,r_ma;
	int mi,l_mi,r_mi;
}dp[maxn][23];
vector<int>v[maxn];
vector<array<int,3>>q;
int dep[maxn];
int a[maxn];
int n,tot;
node operator+(const node& a,const node& b){
	return {
		b.fa,a.sum+b.sum,
		max({a.l_ma+b.r_ma,a.ma,b.ma}),
		max({b.l_ma,b.sum+a.l_ma}),
		max(a.r_ma,a.sum+b.r_ma),
		min({a.l_mi+b.r_mi,a.mi,b.mi}),
		min(b.l_mi,b.sum+a.l_mi),
		min(a.r_mi,a.sum+b.r_mi)
	};
}
node f(int x,int fa){
	return {
		fa,x,
		max(0,x),max(0,x),max(0,x),
		min(0,x),min(0,x),min(0,x)
	};
}
void  dfs(int x,int fa=0)
{
	dp[x][0]=f(a[x],fa);
	for(int i=1;i<=20;i++)
	{
		node L=dp[x][i-1];
		node R=dp[L.fa][i-1];
		dp[x][i]=L+R;
	}
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
void Debug(node a)
{
	cout<<"fa:"<<a.fa<<" sum:"<<a.sum<<endl;
	cout<<"ma:"<<a.ma<<" l_ma:"<<a.l_ma<<" r_ma:"<<a.r_ma<<endl;
	cout<<"mi:"<<a.mi<<" l_mi:"<<a.l_mi<<" r_mi:"<<a.r_mi<<endl;
	cout<<endl;
}
void Debug(int x,int y)
{
	node a=dp[x][y];
	cout<<"dp["<<x<<"]["<<y<<"]"<<endl;
	Debug(a);
}
pii LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	node X = dp[x][0];
	for(int i=20;i>=0;i--)
		if(dep[dp[x][i].fa]>dep[y]){
			X=X+dp[x][i];
			x=dp[x][i].fa;
		}
	if(x==y)return {X.ma,X.mi};

	node Y=dp[y][0];
	for(int i=20;i>=0;i--)
		if(dep[dp[y][i].fa]>=dep[x])
		{
			Y=Y+dp[y][i];
			X=X+dp[y][i];
			y=dp[y][i].fa;
		}
	// for(int i=20;i>=0;i--)
	// 	if(dep[dp[y][i].fa]>=dep[x]){
	// 		Y=Y+dp[y][i];
	// 		y=dp[y][i].fa;
	// 	}
	Debug(X);
	Debug(Y);
	return {
		max({X.ma,Y.ma,X.r_ma+Y.r_ma}),
		min({X.mi,Y.mi,X.r_mi+Y.r_mi})
	};
}


void solve()
{
	cin>>n;
	tot=1;
	v[1].clear();
	a[1]=1;
	q.clear();
	for(int i=1;i<=n;i++)
	{
		char op;
		cin>>op;
		if(op=='+')
		{
			tot++;
			v[tot].clear();
			int fa,w;
			cin>>fa>>a[tot];
			v[fa].push_back(tot);
			v[tot].push_back(fa);
		}
		else
		{
			int x,y,w;
			cin>>x>>y>>w;
			q.push_back({x,y,w});
		}
	}
	dfs(1);
	// Debug(5,0);
	// Debug(5,1);
	for(auto [x,y,w]:q)
	{
		auto [ma,mi]=LCA(x,y);
		if(mi<=w&&w<=ma)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
5
+ 1 -1
+ 2 -1
+ 2 1
+ 3 -1
? 5 4 -3

https://lanqiao-courses.feishu.cn/share/base/form/shrcng7A6oOJRhMAFpRSEcBbbhh
*/