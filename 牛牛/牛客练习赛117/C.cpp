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
int n,m,k;
bool check(int a,int b)
{
	if(k==1&&b)return 0;
	if(k==1)return 1;
	int ds = k/2;
	int x=b/ds;

	if(k&1)a-=x;
	if(a<0)return 0;

	b-=x*ds;
	
	if(b)a-=(k-2*b);
	if(a<0)return 0;
	if(a%k==0)return 1;
	return 0;
}
void solve()
{
	cin>>n>>m>>k;
	if(k==1){
		cout<<m<<endl;
		return ;
	}
	if(k&1)
	{
		int sum=n+m*2;
		int ds=k/2;
		int sd=m/ds;
		if(n<sd){
			cout<<m-n*ds<<endl;
			return ;
		}
		m-=sd*ds;
		n-=sd;

		n%=k;
		sum=n+m*2;
		if(sum<k){
			cout<<n+m<<endl;
			return ;
		}
		
		int ans=0;
		if(n%2==0)
		{
			m-=(sum-n-1)/2;
			cout<<m<<endl;
		}
		else
		{
			m-=(sum-n)/2;
			cout<<m<<endl;
		}
	}
	else
	{
		int sum=n+m*2;
		if(sum%k==0)cout<<0<<endl; // 4 6 4
		else
		{
			int ds=k/2;
			int sd=m/ds;
			m%=sd;
			n%=k;

			sum=n+m*2;
			if(sum<k)cout<<n+m<<endl; // 6 6 4    5 7 4
			else cout<<sum-k<<endl; // 6 7 4   7 7 4
		}
	}
}
/*
4 6 4   0
6 6 4   2
5 7 4   2
6 7 4   0
7 7 4   1
*/
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2
7 2 7
8 2 8



101 50 101    50 
99 50 101     50
*/