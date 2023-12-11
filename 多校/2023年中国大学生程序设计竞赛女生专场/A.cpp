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
vector<int>v[10];
int p[4];
void solve()
{
	for(int i=1;i<=9;i++)v[i].clear();
	v[2].push_back(1);
	v[3].push_back(2);
	v[4].push_back(3);
	p[1]=2;
	p[2]=3;
	p[3]=4;
	for(int i=1;i<=12;i++)
	{
		int x,y;cin>>x>>y;
		
	}
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