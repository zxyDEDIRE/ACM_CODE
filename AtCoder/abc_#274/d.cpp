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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn];
int a[maxn],na;
int b[maxn],nb;
int n,x,y,suma,sumb;
void NO(){cout<<"No"<<endl;}
void YES(){cout<<"Yes"<<endl;}
void solve()
{
	cin>>n>>x>>y;
	int sum=0,io;
	cin>>io;
	x-=io;
	n--;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(i&1)
			a[++na]=t,suma+=t;
		else
			b[++nb]=t,sumb+=t;
	}
	n++;
	if(n&1)
	{
		a[++na]=x,suma+=abs(x);
		b[++nb]=y;sumb+=abs(y);
	}
	else
	{

		a[++na]=x,suma+=abs(x);
		b[++nb]=y;sumb+=abs(y);
	}
	
	

	if(suma&1)return NO();
	for(int i=0;i<=suma;i++)
		dp[i]=0;
	for(int i=1;i<=na;i++)
	{
		for(int j=suma/2;j>=0;j--)
		{
			if(j>=a[i])
				dp[i]=dp[i-a[i]]+a[i];
		}
	}
	if(dp[suma/2]!=suma/2)return NO();


	if(sumb&1)return NO();
	for(int i=0;i<=sumb;i++)
		dp[i]=0;
	for(int i=1;i<=nb;i++)
	{
		for(int j=sumb/2;j>=0;j--)
		{
			if(j>=b[i])
				dp[i]=dp[i-b[i]]+b[i];
		}
	}
	if(dp[sumb/2]!=sumb/2)return NO();

	return YES();







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