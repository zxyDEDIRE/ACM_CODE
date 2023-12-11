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
const int N=2222;
vector<pii>f[2];
bool vis[N][N];
int ch[N][N];
int cnt[2][N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*4;i++)
	{
		for(int j=1;j<=n*4;j++)
			cin>>ch[i][j];
		for(int j=1;j<=n;j++)
		{
			f[0].push_back({i,2*j-1+(i&1 ? 2*n:0)+(i<=2*n? 0:1)});
			f[1].push_back({i,2*j+(i&1 ? 0:2*n)+(i<=2*n? 0:-1)});
		}
	}
	for(int i=0;i<2;i++)
	{
		int flag=1;
		for(auto [x,y]:f[i]){
			cnt[i][ch[x][y]]++;
			if(cnt[i][ch[x][y]]>n)flag=0;
		}
		if(flag)
		{
			cout<<"YES\n";
			for(auto [x,y]:f[i])
				cout<<x<<" "<<y<<endl;
			return ;
		}
	}
	cout<<"NO\n"<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}