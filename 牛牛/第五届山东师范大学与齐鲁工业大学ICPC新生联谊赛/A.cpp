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
ll p[maxn];
ll n,k,s;
void solve()
{
	cin>>n>>k>>s;
	for(int i=1;i<=k;i++)
		p[i]=1,s--;
	if(s<0){
		cout<<"NO\n";
		return ;
	}
	for(int i=1;i<=k;i++)
	{
		ll x=n-1;
		if(s>=x)
		{
			p[i]+=x;
			s-=x;
		}
		else
		{
			p[i]+=s;
			s=0;
		}
	}
	if(s){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
	cout<<k<<endl;
	for(int i=1;i<=k;i++)
		cout<<p[i]<<" ";cout<<endl;
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