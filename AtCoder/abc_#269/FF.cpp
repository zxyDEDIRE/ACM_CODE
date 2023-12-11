/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long
using ll=unsigned long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int mod=998244353;
int n,m,q;
int f(int x,int y)
{
	return (((x-1)*m)%mod+y)%mod;
}
int p(int a,int b,int q)
{
	a%=mod;
	b%=mod;
	q%=mod;
	int ans=a*q%mod+(((q-1)*q/2)%mod)*b%mod;
	return ans%mod;
}
int A(int l,int r,int L,int R)
{
	int a;
	if((l+L)%2==1)a=p(f(l,L),2,(R-L+2)/2);
	else a=p(f(l,L+1),2,(R-(L+1)+2)/2);
	int b;
	if((l+L)%2==1)b=2*m*((R-L+2)/2);
	else b=2*m*((R-(L+1)+2)/2);
	int ans=p(a,b,(r-l+2)/2);
	return ans;
}
void solve()
{
	cin>>n>>m>>q;
	while(q--)
	{
		int l,r,L,R;
		cin>>l>>r>>L>>R;
		int a=p(f(l,L),1,(R-L)+1);
		int sum=p(a,((R-L+1)%mod*m),r-l+1);
		sum-=A(l,r,L,R);
		sum=(sum+mod)%mod;
		sum-=A(l+1,r,L,R);
		sum=(sum+mod)%mod;
		cout<<sum%mod<<endl;
	}
}
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