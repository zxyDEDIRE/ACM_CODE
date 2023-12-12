#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=1e5+100;
struct node{
	ll id,op,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<array<ll,3>>v[maxn];
ll dis[N][550];
bool vis[N][550];
int n,m,k,s,t,q;
void dij()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=(1<<(k+1));j++)
			dis[i][j]=INF;
	dis[s][0]=0;
	priority_queue<node>q;
	// queue<node>q;
	q.push({s,0,0});
	while(!q.empty())
	{
		auto [x,fl,DIS]=q.top();q.pop();
		// auto [x,fl,DIS]=q.front();q.pop();
		if(DIS>dis[x][fl])continue;
		for(auto [y,w,_op]:v[x])
		{
			int op=(_op|fl);
			if(dis[y][op]>dis[x][fl]+w)
			{
				dis[y][op]=dis[x][fl]+w;
				q.push({y,op,dis[y][op]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k>>s>>t;
	int T=(1<<k)-1;
	for(int i=1;i<=m;i++)
	{
		int op,x,y,w;
		cin>>x>>y>>w>>op;
		op--;
		v[x].push_back({y,w,1<<op});
		v[y].push_back({x,w,1<<op});
	}
	dij();
	for(int i=0;i<(1<<k);i++)
		for(int j=0;j<(1<<k);j++)
			if(i!=j&&(i&j)==i){
				for(int k=1;k<=n;k++)
					dis[k][j]=min(dis[k][i],dis[k][j]);
			}
	cin>>q;
	while(q--)
	{
		int num,fl=0,x;
		cin>>num;
		while(num--){
			cin>>x;
			x--;
			fl|=(1<<x);
		}

		if(dis[t][T^fl]==INF)cout<<-1<<endl;
		else cout<<dis[t][T^fl]<<endl;
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
/*
0 1 2
4 5 3 1 4
1 2 5 1
1 3 3 1
2 4 6 2
3 4 1 2
1 4 10 3
3
1 1
1 2
1 3

5 10 4 1 4
3 1 503750011 3
1 2 1 1
1 4 59221752 3
2 3 1 1
5 4 902461647 2
2 4 393673070 3
3 2 1 1
4 1 102038464 3
2 3 390756765 2
2 4 1 1
1
1
1 

5 2 4 1 4
1 4 59221752 3
4 1 102038464 3
1
1
1 
*/