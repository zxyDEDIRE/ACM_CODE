/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
const int maxn=2e6+100;
const int M = 2e6;
int num_1=0,num_0=0;
int ff[maxn];
string str;
ll n,m;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int mull(int a,int b){	int qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

//求最大公因数
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b){
    if(b==0){x=1;y=0;}
    else{Extended_gcd(b,a%b);long t=x;x=y;y=t-(a/b)*y;}
}
//计算不大的C(n,m)
int C(int a,int b){
	if(a==b)return 1;
	if(a==0)return 0;
    if(b>a)return 0;
    if(b<0||a<0)return 0;
    b=(ff[a-b]%mod*ff[b])%mod;a=ff[a];
    int c=gcd(a,b);a/=c;b/=c;Extended_gcd(b,M);x=(x+mod)%mod;
    x=(x*a)%mod;return x;
}
int A(int n,int m){return (C(n,m)*ff[m])%mod;}

void solve()
{
	cin>>n>>m>>str;
	for(int i=0;i<n;i++)
		if(str[i]=='0')num_0++;
		else num_1++;
	// int tot=mull(mull(A(n,n),ksm(A(num_0,num_0),mod-2)),ksm(A(num_1,num_1),mod-2));
	int tot=C(n,num_0);
	int ans=0;
	if(m&1)
	{
		ans=(ans+mull(C(num_0-1,m/2-1),C(num_1-1,m/2) ))%mod;
		ans=(ans+mull(C(num_0-1,m/2),C(num_1-1,m/2-1) ))%mod;
	}
	else
	{
		int ans_1=C(num_0-1,m/2-1);
		int ans_2=C(num_1-1,m/2-1);
		ans=(ans+mull(ans_1,ans_2)*2)%mod;
	}
	ll a=ans;
	ll b=((tot+mod-ans)%mod);
	cout<<a<<" "<<b<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
/*
00111

*/