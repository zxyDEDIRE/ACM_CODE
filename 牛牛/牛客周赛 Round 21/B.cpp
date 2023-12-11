#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,0,1,-1,0,0,2,-2};
const int dy[]={0,1,-1,0,0,2,-2,0,0};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1111;
char mp[N][N];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[i][j]='.';
	while(k--)
	{
		int x,y;char ch;
		cin>>x>>y>>ch;
		for(int i=0;i<9;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			mp[xx][yy]=ch;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<mp[i][j];
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}