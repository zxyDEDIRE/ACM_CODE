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
map<ll,ll>mp;
int n;
void solve()
{
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mp[x]++;
	}
	int q;cin>>q;
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		ll a=l*l-4*r;
		ll b=sqrt(a);
		if(b*b!=a|| (l+b)%2!=0||(l-b)%2!=0)cout<<0<<" ";
		else
		{
			ll x=(l+b)/2;
			ll y=(l-b)/2;
			if(x==y)
			{
				if(!mp.count(x))cout<<0<<" ";
				else cout<<mp[x]*(mp[x]-1)/2<<" ";
			}
			else cout<<mp[x]*mp[y]<<" ";
		}
	}
	cout<<endl;
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