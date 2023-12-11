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
const int INF=1e9+7;
const int maxn=1e6+100;
ll n,p,P;
int PHI(int x)
{
	//O(sqrt(x)
	int ans=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			ans=ans*(i-1)/i;
		}
	if(x>1)ans=ans*(x-1)/x;
	return ans;
}
int ksm(int b,int p,int mod){int r=1;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void solve()
{
	cin>>n>>p;
	P=PHI(p);


	int x=ksm(2,n,p);
	if(gcd(n,p)!=0)
		x=ksm(2,n,P);

	int y=ksm(2,x,p);
	if(gcd(x,p)!=0)
		x=ksm(2,n,P);

	cout<<y<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
