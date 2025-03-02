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
bool vis[maxn];
string s;
int n;
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s.substr(i,5)=="mapie")
		{
			ans++;
			s[i+2]='z';
		}
		if(s.substr(i,3)=="map")ans++;
		if(s.substr(i,3)=="pie")ans++;
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
map
pie

mapie
*/