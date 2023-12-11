/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=507;
int pre[N][N];
int mp[N][N];
int n,m,k,ans;
int f(int a,int b,int x,int y)
{
	int now=pre[x][y]-pre[x][b-1]-pre[a-1][y]+pre[a-1][b-1];
	if(now<=k)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mp[i][j];
		}
	int flag,N=n,M=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			N=n;
			M=m;
			for(int I=i;I<=n;I++)
			{
				for(int J=j;J<=m;J++)
				{
					int now=f(i,j,I,J);
					if(!now){
						M=J;
						break;
					}
					else ans+=now;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}