#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll p[maxn];
int n;
void NO(){cout<<"No\n";}
pii f(ll x)
{
	vector<int>v;
	while(x){
		v.push_back(x%2);
		x/=2;
	}
	pii now={-1,-1};
	int len=v.size();
	now.first=len;
	for(int i=0;i<v.size();i++)
		if(v[i]==1){
			now.second=i;
			break;
		}
	if(now.second==-1)return {(1ll<<(len+1)),(1ll<<len)};
	for(int i=now.second+1;i<now.first;i++)
		if(v[i]==0)
			return {-1,-1};
	now.first=(1ll<<now.first);
	now.second=(1ll<<now.second);
	return now;
}
void solve()
{
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	if(sum%n)return NO();
	sum/=n;
	// cout<<"sum "<<sum<<endl;
	map<ll,int>mp;
	for(int i=1;i<=n;i++) 
	{
		int x=p[i]-sum;
		if(x==0)continue;
		pii now=f(abs(x));
		if(now.first==-1)return NO();
		if(x>0)
		{
			cout<<now.first<<" "<<-now.second<<" "<<x<<endl;
			mp[now.first]++;
			mp[now.second]--;
		}
		else
		{
			cout<<-now.first<<" "<<now.second<<" "<<x<<endl;
			mp[now.first]--;
			mp[now.second]++;
		}
	}
	ll ans=0;
	for(auto [x,y]:mp)
		if(y!=0)return NO();
	cout<<"Yes\n";
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
/*

*/