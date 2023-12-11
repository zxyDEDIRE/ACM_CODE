#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=4e3+100;
struct node{
	int x,y;
}p[maxn];
int dp[N][N]; //
int n,m;
void solve()
{
	cin>>n;
	int sa=0,sb=0;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,sa+=p[i].x;
	for(int i=1;i<=n;i++)
		cin>>p[i].y,sb+=p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y!=b.y)
			return a.y<b.y;
		return a.x<b.x;
	});
	cin>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+p[i].x+j*p[i].y);
	for(int i=0;i<=n;i++)
		if(sa+i*sb-dp[n][i]<=m){
			cout<<i<<endl;
			return ;
		}
	cout<<-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}