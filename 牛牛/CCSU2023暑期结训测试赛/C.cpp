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
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=333;
pp(3) p[maxn];
ll dis[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)dis[i][j]=INF;
	for(int i=1;i<=m;i++)
		cin>>p[i][0]>>p[i][1]>>p[i][2];
	sort(p+1,p+1+m,[&](pp(3)a,pp(3)b){
		return a[2]<b[2];
	});
	int ans=0;
	for(int _i=1;_i<=m;_i++)
	{
		int flag=0;
		auto [x,y,w]=p[_i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][x]+w+dis[y][j])
				{
					flag=1;
					dis[i][j]=dis[i][x]+w+dis[y][j];
					dis[j][i]=dis[i][j];
				}
				if(dis[i][j]>dis[i][y]+w+dis[x][j])
				{
					flag=1;
					dis[i][j]=dis[i][y]+w+dis[x][j];
					dis[j][i]=dis[i][j];
				}
			}
		if(!flag)ans++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
300*150*300*300
*/