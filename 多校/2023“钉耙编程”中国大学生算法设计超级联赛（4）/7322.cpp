/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int INF=1e18+7;
const int maxn=1e6+100;
const int N=555;
int dis[N][N];
int cnt[N][N];
int a[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=0,dis[i][j]=INF;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=w;
		dis[x][y]=w;
		cnt[x][y]=1;
	}
	int mi=INF;
	int ans=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j]%mod;
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j])
				{
					cnt[i][j]=(cnt[i][j]+cnt[i][k]*cnt[k][j])%mod;
				}
			}
		for(int i=1;i<k;i++)
		{
			if(a[k][i])
			{
				if(a[k][i]+dis[i][k]<mi){
					mi=a[k][i]+dis[i][k];
					ans=cnt[i][k];
				}
				else if(a[k][i]+dis[i][k]==mi){
					ans=(ans+cnt[i][k])%mod;
				}
			}
		}
	}
	if(mi==INF)ans=mi=-1;
	cout<<mi<<" "<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}