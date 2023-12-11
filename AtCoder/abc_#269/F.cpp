/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int mod=998244353;
ll n,m,q;
int f(int x,int y)
{
	return (((x-1)*m)%mod+y)%mod;
}
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
int p(int a,int b,int q)
{
	a%=mod;
	b%=mod;
	q%=mod;
	int ans=((a*q)%mod+((((q*(q-1))%mod)*fp(2,mod-2)%mod)%mod*b%mod)%mod)%mod;
	return ans%mod;
}
int sub_1(int l,int r,int L,int R)
{
	int a=0,b=0,x=0;
	if((l+L)%2==1)a=f(l,L);
	else if(L+1<=R)a=f(l,L+1);

	if((l+L)%2==1)x=(r-l+1)/2;
	else x=(r-(l+1)+1)/2;
	b=2;

	int ans_1=p(a,b,x);


	a=ans_1;
	b=m*x;
	x=(R-L+1)/2;

	int res_1=p(a,b,x);









	a=0,b=0,x=0;
	l++;

	if((l+L)%2==1)a=f(l,L);
	else if(L+1<=R)a=f(l,L+1);

	if((l+L)%2==1)x=(r-l+1)/2;
	else x=(r-(l+1)+1)/2;

	b=2;

	int ans_2=p(a,b,x);

	a=ans_1;
	b=m*x;
	x=(R-(L+1)+1)/2;

	int res_2=p(a,b,x);

	return (res_1+res_2)%mod;


}
void solve()
{
	cin>>n>>m>>q;
	while(q--)
	{
		int l,r,L,R;
		cin>>l>>r>>L>>R;
		int a=p(f(l,r),1,(r-l)+1);
		cout<<a<<endl;
		// int b=(m*(r-l+1))%mod;
		// int x=(R-L+1);
		// int ans=p(a,b,x);
		// cout<<ans<<endl;
		// ans-=sub_1(l,r,L,R);


		//cout<<ans<<endl;
	}
}
/*
5 4 1
1 3 2 4
*/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}