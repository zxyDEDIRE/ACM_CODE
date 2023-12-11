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
int n,x;
void solve()
{
	cin>>n>>x;
	int ma=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ma=p[1];
	for(int i=2;i<=n;i++)
		ma=max(ma,p[i]-p[i-1]);
	ma=max(ma,(x-p[n])*2);
	cout<<ma<<endl;
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
3 7
0 1 2 5 7
 1 1 3 2

*/