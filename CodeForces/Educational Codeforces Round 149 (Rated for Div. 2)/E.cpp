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
const int maxn=1e6+100;
const int M=9e5+100;
ll F[M],INF[M];
int a[maxn];
int p[maxn];
ll ans=1;
int n,m;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll C(ll n,ll m){
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;
}
ll A(ll n,ll m){return (C(n,m)*F[m])%mod;}

void f(int k)
{
	int sum=(1<<(k-1));
	if(k==1)sum=2;
	int len=n/sum;
	// cout<<k<<" "<<sum<<" "<<len<<endl;
	// for(int i=1;i<=n;i++)
		// cout<<a[i]<<" ";cout<<endl;
	int tot=0;
	for(int i=1;i<=n;i+=len)
	{
		int cnt=0;
		int cnt_1=0;
		for(int j=i;j<=(i+len-1);j++)
		{
			if(a[p[j]]==k)cnt++;
			if(a[p[j]]==k-1)cnt_1++;
		}
		if(cnt>1){cout<<0<<endl;exit(0);}
		if(k!=1&&cnt_1==0)ans=(ans*2);//,cout<<"INT\n";
		tot+=cnt;
	}
	// cout<<ans<<" "<<tot<<endl;
	// cout<<"F[sum-tot] "<< F[sum-tot]<<endl;
	ans=(ans*F[sum-tot])%mod;
	// cout<<ans<<endl;
	// cout<<endl;
}
void solve()
{
	cin>>m;
	n=(1<<m);
	int s=1,t=0,k=1;
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=k;
		t++;if(s==t)s*=2,t=0,k++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==-1)p[i]=0;
	}
	a[0]=100000000;
	// cout<<ans<<endl;
	for(int i=m;i>=1;i--)
		f(i);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/