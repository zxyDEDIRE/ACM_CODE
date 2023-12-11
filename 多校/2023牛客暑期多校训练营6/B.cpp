#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10,mod=998244353;
long long ksm(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
long long c[N][N];
long long sum[N][N];
long long dp[N][N];
long long a[N][N];
long long A(int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++)
		(ans*=i)%=mod;
	return ans;
}
long long f(int x)
{
	return A(2*x)/A(x)/A(x);
}
void init(int n=N-10){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=0;k<=i;k++){
				sum[i][j]=(sum[i][j]+c[i][k]*c[j][k]%mod)%mod;
			}
		}
	}
	

}
int s[N],t[N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(s+1,s+n+1);
	sort(t+1,t+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long cnt=abs(s[i]-t[j]);
			int x=i-1,y=j-1,\
				x1=n-i,y1=n-j;
			if(x>y) swap(x,y);
			if(x1>y1) swap(x1,y1);
			ans+=1ll*cnt*sum[x][y]%mod*sum[x1][y1]%mod;
			ans%=mod;
		}
	}
	cout<<ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// clock_t start, finish;
	// start = clock();
	init();
	// finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
	solve();
	return 0;
}
