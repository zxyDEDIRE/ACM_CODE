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
struct node{
	int l,r,a,b;
}p[maxn];
int f[maxn];
int a[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		auto &[l,r,a,b]=p[i];
		cin>>l>>r>>a>>b;
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++)
		cin>>a[i];

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