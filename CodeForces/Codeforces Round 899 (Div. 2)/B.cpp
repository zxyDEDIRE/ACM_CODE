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
vector<int>a[111],b[111];
map<int,int>mp;
set<int>s;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=50;i++)
		a[i].clear(),b[i].clear();
	mp.clear();
	s.clear();
	for(int i=1;i<=n;i++){
		int k,x;cin>>k;
		while(k--){
			cin>>x;
			a[i].push_back(x);
			b[x].push_back(i);
			mp[x]++;
			s.insert(x);
		}
	}
	int ans=0;
	int tot=s.size();
	for(auto i:s)
	{
		map<int,int>_mp;
		for(auto j:b[i])
		{
			for(auto x:a[j])
			{
				_mp[x]++;
			}
		}
		int now=tot;
		for(auto [x,y]:_mp)
			if(mp[x]==y)
				now--;
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