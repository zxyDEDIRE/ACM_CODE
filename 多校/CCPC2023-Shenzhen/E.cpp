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
int n;
void solve()
{
	cin>>n;
	map<int,int>mp;
	int ma=-1,mb=-1;
	int fa=0,fb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int x=++mp[p[i]];
	}
	for(auto [x,y]:mp)
	{
		if(y>mb)
		{
			mb=y;
			fb=x;
		}
		if(ma<mb)
		{
			swap(ma,mb);
			swap(fa,fb);
		}
	}
	mp.clear();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		mp[p[i]]++;
		int now=(mp[fa]|mp[fb]);
		ans=max(ans,now);
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