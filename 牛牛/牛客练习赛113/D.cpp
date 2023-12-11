/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int INF=1e18+7;
const int maxn=1e6+100;
int q[maxn];
int p[maxn];
int n,a,x,b,y;
int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
void solve()
{
	cin>>n>>a>>x>>b>>y;
	int sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	for(int i=1;i<=n;i++)
		q[i]=INF;

	for(int i=0;i<n;i++)
	{
		int now=(i*(x%n))%n;
		q[now]=min(q[now],i*a);
	}

	int mi=INF;
	for(int i=0;i<n;i++)
	{
		int now=((sum-i*(y%n))%n+n)%n;
		if(now!=0)
		{
			if(q[n-now]!=INF)
				mi=min(mi,i*b+q[n-now]);
		}
		else mi=min(mi,i*b);

		// cout<<i<<" "<<mi<<" "<<now<<endl;
	}
	if(mi!=INF)
		cout<<mi<<endl;
	else cout<<-1<<endl;
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