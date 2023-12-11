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
const int N=1111;
int mp[N][N];
int n,m;
int h[N],l[N];
void solve()
{
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=max(n,m);i++){
		h[i]=l[i]=1e9;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			h[i]=min(h[i],mp[i][j]);
			l[j]=min(l[j],mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==min(l[j],h[i])){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}