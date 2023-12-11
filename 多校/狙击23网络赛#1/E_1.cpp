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
int F[maxn],INF[maxn];
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
void init(int N)
{
	F[0]=INF[0]=1;
	for(int i=1;i<=N;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
}
int C(int n,int m){
	return (F[n]*INF[n-m])%mod*INF[m]%mod;  //mod
}
int ans[maxn];
int cnt[maxn];
vector<int>p;
int n,m;
void solve()
{
	cin>>n>>m;
	p.resize(n);
	for(int i=0;i<n;i++)
		cin>>p[i];
	sort(p.begin(),p.end(),[&](int a,int b){return a>b;});
	for(int i=1;i<=m;i++)
	{
		if(i<p[0])continue;
		ans[i]=1;
		for(int j=0;j<n;j++)
		{
			ans[i]=ans[i]*C(i,p[j]);
			ans[i]%=mod;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		init(1e5);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/