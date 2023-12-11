/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
double dis[maxn][20];
struct node{
	int x,mp,t;
	double ans;
	bool operator<(const node &a)const{
		return a.ans<ans;
	}
};
pii p[100];
bool vis[maxn][20];
double res=1e18;
int n,m,st;
double f(int x,int y)
{
	return hypot(p[x].first-p[y].first,p[x].second-p[y].second);
}
void bfs()
{
	for(int i=0;i<1<<n+m;i++)
		for(int j=1;j<=n+m;j++)
			dis[i][j]=1e18;
	priority_queue<node>q;
	q.push({0,0,1,0.0});
	while(!q.empty())
	{
		auto [x,mp,t,ans]=q.top();q.pop();
		if(vis[mp][x])continue;
		vis[mp][x]=1;
		if((mp&st)==st)
		{
			res=min(ans+1.0*f(0,x)/t,res);
			continue;
		}
		for(int i=1;i<=n+m;i++)
		{
			if(mp&(1<<(i-1)))continue;
			int mp_1=(mp|(1<<(i-1)));
			int t_1=t;
			if(dis[mp_1][i]>ans+1.0*f(x,i)/t)
			{
				// cout<<mp<<" "<<x<<" "<<t<<" "<<ans<<endl;
				dis[mp_1][i]=dis[mp][x]+1.0*f(x,i)/t;
				q.push({i,mp_1,t_1,dis[mp_1][i]});
				// cout<<mp_1<<" "<<i<<" "<<t_1<<" "<<dis[mp_1][i]<<endl;
				// cout<<endl;
			}
		}
	}
	printf("%.6lf\n",res);
}
void solve()
{
	cin>>n>>m;
	st=((1ll<<n)-1);
	p[0].first=0;p[0].second=0;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=n+1;i<=m+n;i++)
		cin>>p[i].first>>p[i].second;
	bfs();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		// solve();
	for(int i=1;i<=(1<<17);i++)
	{
		for(int n=1;n<=(1<<17);n++)
		{
			int x=(     i&(1<<n)-1    );
			int y=(     i&((1<<n)-1)    );
			if(x!=y)cout<<"i"<<endl;
		}
	}
	
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}