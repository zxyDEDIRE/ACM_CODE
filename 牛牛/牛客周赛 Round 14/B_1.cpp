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
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
void NO(){cout<<-1<<endl;}
void solve()
{
	ll x,y;
	cin>>x>>y;
	ll ans=0;
	int a=0,b=0;
	while(x%5==0)a++,x/=5;
	while(y%5==0)b++,y/=5;
	if(b<a)return NO();
	// cout<<a<<" "<<b<<endl;
	ans+=b-a;

	a=0,b=0;
	while(x%6==0)a++,x/=6;
	while(y%6==0)b++,y/=6;
	if(a<b)return NO();
	// cout<<a<<" "<<b<<endl;
	ans+=a-b;
	if(x!=y)return NO();
	cout<<ans<<endl;
}
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