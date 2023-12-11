#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e3+10;
const int N=1e3+10;
long long fac[maxn],inv[maxn];
long long bt[N][200];
int in[N];
int n,m;
int p=62;
long long ksm(long long b,long long p){long long r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void init(int n=1e3+10)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)
	{
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
long long C(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve()
{
	cin>>n>>m;
	// scanf("%d%d",&n,&m);
	int B=(n+p-1)/p;
	for(int i=0;i<n;i++)
	{
		in[i]=0;
		for(int j=0;j<B;j++){
			bt[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		// scanf("%d%d",&x,&y);
		x--;y--;
		bt[x][y/p]|=(1ll<<(y%p));
		bt[y][x/p]|=(1ll<<(x%p));
		in[x]++;in[y]++;
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(in[i]<4)continue;
		for(int j=i+1;j<n;j++)
		{
			if(in[j]<4)continue;
			int t=0;
			for(int k=0;k<B;k++)
			{
				t+=__builtin_popcountll(bt[i][k]&bt[j][k]);
			}
			int f=((bt[i][j/p]&(1ll<<(j%p)))>0);
			if(t<4)continue;
			long long res=C(t,4);
			int t1=in[i],t2=in[j];
			t1-=f;t2-=f;
			ans=(ans+res*((C(t1-4,2)+C(t2-4,2))%mod)%mod)%mod;
		}
	}
	cout<<ans<<endl;
	// printf("%lld\n",ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;
	cin>>__;
	// scanf("%d",&__);
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
