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
int n,k;
void solve()
{
	cin>>n>>k;
	int ans=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int x=p[i]%k;
		int y=k-x;
		if(x==0)ans++;
		else if(mp.count(y)&&mp[y])
			ans++,mp[y]--;
		else mp[x]++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}