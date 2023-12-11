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
const int maxn=1e6+100;
const int M=1e6+100;
ll F[M],INF[M];

int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

int C(int n,int m){
	// mod
	return (F[n]*INF[n-m])%mod*INF[m]%mod;  //mod
	
}
int in[maxn];
int w[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		in[i]=0,w[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		in[x]++;
		in[y]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=in[i];
		for(int j=2;j<=x;j++)
		{
			w[j]=(w[j]+C(x,j))%mod;
		}
	}
	for(int i=2;i<n;i++){
		ans=(ans^w[i]);
	}
	cout<<ans<<endl;

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