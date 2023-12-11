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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
const int M=2e6+100;
int F[M],INF[M],n;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void init()
{
	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
}
void solve()
{
	int ans=(F[n]*F[n])%mod;
	ans=(ans*INF[n*2+1])%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	while(cin>>n)
		solve();
	// cout<<ksm(20,mod-2)<<endl;
	// cout<<(F[3]*INF[5])%mod<<endl;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1.1   |2 3
2.2   |3 4 5
3.6   |4 5 6 7
4.14  |5 6 7 8 9
*/