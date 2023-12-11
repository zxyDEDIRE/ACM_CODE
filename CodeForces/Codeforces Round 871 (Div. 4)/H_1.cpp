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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e5+100;
ll dp[100];
int a[maxn];
int n,k;

int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int mull(int a,int b){int qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<=n;i++)
		for(int j=0;j<66;j++)
			dp[j]=0;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[a[i]]++;
		for(int j=0;j<66;j++)
		{
			int x=(a[i]&j);
			dp[a[i]&j]+=dp[j];
			dp[x]%=mod;
		}
	}
	ll ans=0;
	for(int i=0;i<66;i++)
	{
		int cnt=0;
		for(int j=0;j<6;j++)
			if(i&(1<<j))cnt++;
		if(cnt==k)ans+=dp[i],ans%=mod;
	}
	ans=mull(ans,ksm(2,mod-2));
	cout<<ans<<endl;
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