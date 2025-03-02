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
const ll mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[555][555];
ll p[555][555][111];
int n,m,q,k;
void solve()
{
	cin>>n>>m>>q>>k;
	// n=500;m=500;
	// q=0;
	// k=100;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
				mp[i][j]=k+10;
			for(int t=1;t<=k;t++)
				p[i][j][t]=0;
		}
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		mp[x][y]=min(mp[x][y],t);
	}
	p[1][1][0]=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int t=1;t<=k;t++)
			{
				int x,y;
				if(mp[i][j]<=t)continue;
				x=i,y=j;
				while(x)
				{
					x--;
					if(mp[x][y]<=t)break;
					p[i][j][t]+=p[x][y][t-1];
				}
				x=i;
				while(y)
				{
					y--;
					if(mp[x][y]<=t)break;
					p[i][j][t]+=p[x][y][t-1];
				}
			}
		}
	}

	for(int t=1;t<=k;t++)
	{
		cout<<"time:"<<t<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<p[i][j][t]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}

	int mi=k+10;
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		if(p[n][m][i])
		{
			mi=min(mi,i);
			ans+=p[n][m][i];
		}
	}
	if(!ans)cout<<-1<<endl;
	else cout<<ans<<" "<<mi<<endl;
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
/*
1
2 3 2 5
1 3 1
2 2 3
*/