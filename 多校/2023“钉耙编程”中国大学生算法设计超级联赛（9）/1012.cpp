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
const int maxn=1e4+100;
vector<int>v[maxn];
int b[maxn][111];
int t[maxn];
int in[maxn];
int ans[maxn];
int n,m,k;
void f(int s)
{
	for(int i=1;i<=m;i++)t[i]=-1;
	int cnt_1=0;
	int cnt_2=0;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<m;i++)
		cin>>ans[i];
	for(int i=1;i<=n;i++)
		f(i);
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