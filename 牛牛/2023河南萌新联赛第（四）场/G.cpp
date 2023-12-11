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
const int maxn=1e6+100;
const int M=2e5+100;
int F[M],INF[M];
int p[maxn];
int n,k;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int mull(int a,int b){int qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

int C(int n,int m){
	// mod
	if(m==0)return 1;
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;  //mod
	
}
void solve()
{
	cin>>n>>k;
	int flag=0;
	map<int,int>mp;
	int s=0,t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(mp.count(p[i]))s=mp[p[i]],t=i,flag=1;
		else mp[p[i]]=i;
	}
	// if(k==1)cout<<n<<endl;
	// else if(k==n)cout<<1<<endl;
	if(flag)
	{
		//1 2 3 0 3 4 5
		int ans=C(n,k);
		s=s-1;
		t=n-t;
		for(int i=0;i<=min(s,k-1);i++)
		{
			if(k-i-1<0)continue;
			if(k-i-1>t)continue;
			int now=mull(C(s,i),C(t,k-i-1));now%=mod;
			ans=(ans-now+mod)%mod;			
		}
		cout<<ans<<endl;
	}
	else
	{
		cout<<C(n,k)<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
7 4
1 2 3 6 3 4 5
31

1
4 2
1 1 2 3



*/