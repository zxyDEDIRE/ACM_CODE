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
int mp[maxn];
int p[maxn];
int Q,n,m;
void solve()
{
	cin>>Q>>n>>m;
	for(int i=1;i<=Q;i++)mp[i]=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mp[x]=i;
	}
	vector<int>v;
	int mi=INF;
	int fl=0;
	for(int i=1;i<=m;i++)
	{
		int x;cin>>x;
		if(mp[x]!=0)
		{
			mi=min(mi,mp[x]);
			if(fl==0)fl=x;
		}
	}
	if(mi==INF||mp[fl]==mi)cout<<"fine\n";
	else cout<<"deadlock\n";
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
g c a b
f e b a

0 0 4 3
0 0 3 4

c a b
e c b a

1 3 2
1 2 3
*/