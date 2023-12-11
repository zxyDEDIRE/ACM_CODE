#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int p[maxn];
int a[maxn];
int n;
void f()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=1;
	sort(p+1,p+1+n);
	n--;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			cout<<p[i]<<" "<<p[j]<<" "<<__gcd(p[i],p[j])*(n-j+1)<<endl;
			ans+=__gcd(p[i],p[j])*(n-j+1);
			a[i]*=(n-j+1),a[j]*=(n-j+1);
		}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		p[i]*=a[i];
		cout<<p[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ans+=__gcd(p[i],p[j]);
			cout<<p[i]<<" "<<p[j]<<" "<<__gcd(p[i],p[j])<<endl;
		}
	cout<<ans<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		// cin>>p[i];
	sort(p+1,p+1+n);
	n--;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ans+=__gcd(p[i],p[j])*(n-j+1);
			// cout<<__gcd(p[i],p[j])<<" "<<(n-j)<<endl;
			// for(int k=j+1;k<=n;k++)
			// 	ans+=__gcd(p[i],p[j]);
		}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--){
		// solve();
		f();
	}
	return 0;
}
/*
2 3 6 12 17

2 6 12 17

4
6 8 9 9
  
  2*2
    3
    1
2<=n<=8e4
1<=p[i]<=1e5
*/