/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int maxn=2e6+100;
string str;
int n,m;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int mull(int a,int b){
	return (a*b)%mod;
}
const int M=2e6;
int F[maxn],INF[maxn];

int C(int n,int m){
	if(n==m||m==0)return 1;
	if(n==0)return 0;
	if(m>n)return 0;
	return mull(mull(F[n],INF[n-m])%mod,INF[m])%mod;  //mod
}
void init()
{
	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=(F[i-1]*i)%mod;
		INF[i]=ksm(F[i],mod-2);
	}
}
void solve()
{
	int num_1=0,num_0=0;
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
		// cout<<C(num_0-1,m/2)<<" "<<C(num_1-1,m/2-1) <<endl;
	}
	else
	{
		int ans_1=C(num_0-1,m/2-1);
		int ans_2=C(num_1-1,m/2-1);
		ans=(ans+mull(ans_1,ans_2)*2)%mod;
	}
	cout<<ans<<" "<<((tot+mod-ans)%mod)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	
	init();
	solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
00111

*/