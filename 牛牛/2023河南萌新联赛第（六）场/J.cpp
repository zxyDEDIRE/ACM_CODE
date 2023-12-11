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
const int N=111;
int a[N],b[N];
int mp[N][N];
ll s[N][N];
int n,m;
ll get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			mp[i][j]=a[i]*b[j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
		}
	int X;cin>>X;
	ll ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int _i=i;_i<=n;_i++)
			{
				for(int _j=j;_j<=m;_j++)
				{
					int sum=get(i,j,_i,_j);
					if(sum>X)continue;
					ma=max(ma,1ll*(_i-i+1)*(_j-j+1));
				}
			}
		}
	}
	cout<<ma<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}