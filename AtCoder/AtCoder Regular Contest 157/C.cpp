/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int M = 2e5+10;
const int N=2e3+10;
int ff[M+5];  //打表，记录n!，避免重复计算
int dp[N][N];
char mp[N][N];
int n,m;
//求最大公因数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
 
//计算不大的C(n,m)
int C(int a,int b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%mod;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+mod)%mod;
    x=(x*a)%mod;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
	if(n<=0||m<=0)return 1;
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%mod;
        b=m%mod;
        n/=mod;
        m/=mod;
        ans=(ans*C(a,b))%mod;
    }
    return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=mod;
			if(mp[i][j]=='Y')
			{
				if(mp[i-1][j]=='Y')
					dp[i][j]+=Combination(i+j-3,i-2);
				dp[i][j]%=mod;
				if(mp[i][j-1]=='Y')
					dp[i][j]+=Combination(i+j-3,i-1);
				dp[i][j]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='Y')
			{
				if(mp[i+1][j]=='Y')
					ans+=(Combination(i+j-2,i-1)+2*dp[i][j])%mod*Combination(n+m-i-j-1,n-i-1)%mod;
				ans%=mod;
				if(mp[i][j+1]=='Y')
					ans+=(Combination(i+j-2,i-1)+2*dp[i][j])%mod*Combination(n+m-i-j-1,n-i)%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	ff[0]=1;
    for(int i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%mod;
	solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}