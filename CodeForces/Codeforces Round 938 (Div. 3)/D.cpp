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
int a[maxn];
int b[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i],mp[b[i]]++;
	int ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(mp.count(a[i]))
		{
			mp[a[i]]--;
			if(mp[a[i]]>=0)cnt++;
		}
	}
	if(cnt>=k)ans++;
	// cout<<"1 "<<m<<" "<<ans<<endl;
	for(int i=2;i+m-1<=n;i++)
	{
		if(mp.count(a[i-1]))
		{
			if(mp[a[i-1]]>=0)cnt--;
			mp[a[i-1]]++;
		}
		if(mp.count(a[i+m-1]))
		{
			mp[a[i+m-1]]--;
			if(mp[a[i+m-1]]>=0)cnt++;
		}
		if(cnt>=k)ans++;
		// cout<<i<<" "<<i+m-1<<" "<<cnt<<" "<<ans<<endl;
	}
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
/*
7 4 3
4 1 2 3 4 5 6
4 1 2 3
  1 2 3 4
    2 3 4 5
      3 4 5 6

1 2 3 4
*/