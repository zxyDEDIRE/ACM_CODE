/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
double pre[maxn];
double p[maxn];
int n,f;
bool check(double mid)
{
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+p[i]-mid;
	double mi=0;
	for(int i=0,j=f;j<=n;i++,j++)
	{
		mi=min(mi,pre[i]);
		if(pre[j]-mi>=0)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>f;
	double l=0,r=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],r=max(r,p[i]);

	while(l<r-0.0001)
	{
		double mid=(l+r)*0.5;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	cout<<int(r*1000)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}