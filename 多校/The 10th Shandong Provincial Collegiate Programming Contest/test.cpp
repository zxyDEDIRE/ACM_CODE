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
int a[maxn],b[maxn];
map<int,int>mpa,mpb;
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],mpa[a[i]]++;
	for(int i=1;i<=m;i++)
		cin>>b[i],mpb[b[i]]++;
	sort(b+1,b+1+m,[&](int a,int b){
		if(mpb[a]!=mpb[b])return mpb[a]>mpb[b];
		int fa=mpa.count(a^k);
		int fb=mpa.count(b^k);
	});
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}