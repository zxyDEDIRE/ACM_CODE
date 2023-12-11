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
__int128 pre[maxn];
__int128 p[maxn];
ll a[maxn];
ll n;
__int128 sum(int l,int r){
	return pre[r]-pre[l-1];
}
__int128 f(int l,int r){
	return p[r]/p[l-1];
}
void solve()
{
	cin>>n;
	vector<int>v;
	p[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
		if(a[i]>1)v.push_back(i);
	}
	__int128 now=1;
	for(int i=1;i<=n;i++)
	{
		now*=a[i];
		p[i]=now;
		if(now>pre[n]){
			cout<<v[0]<<" "<<v.back()<<endl;
			return ;
		}
	}
	if(v.size()<2){
		cout<<"1 1\n";
		return ;
	}

	__int128 ans=sum(1,n);
	ll l=1,r=1;
	for(int i=0;i<v.size();i++)
	{
		for(int j=i;j<v.size();j++)
		{
			__int128 now=f(v[i],v[j])+sum(1,n)-sum(v[i],v[j]);
			if(now>ans){
				ans=now;
				l=v[i];
				r=v[j];
			}
		}
	}
	cout<<l<<" "<<r<<endl;
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