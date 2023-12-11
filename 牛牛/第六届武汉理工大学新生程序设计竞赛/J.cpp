#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,0,1,-1,1,-1,1,-1};
const int dy[]={0,1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vx[maxn];
bool vy[maxn];
map<pii,bool>mp;
pp(3) p[maxn];
int n,m,q;
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++)
		cin>>p[i][0]>>p[i][1]>>p[i][2];
	ll ans=0;
	for(int i=q;i>=1;i--)
	{
		auto [op,x,y]=p[i];
		if(op==1)
		{
			if(x==1)vx[y]=1;
			else vy[y]=1;
		}
		else
		{
			for(int j=0;j<5;j++)
			{
				int xx=x+dx[j];
				int yy=y+dy[j];
				if(xx>n||xx<1||yy>m||yy<1)continue;
				if(mp.count({xx,yy}))continue;
				if(!vx[xx]&&!vy[yy])ans++,mp[{xx,yy}]=1;
			}
		}
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