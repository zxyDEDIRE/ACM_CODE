
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=2e4+1;
struct node{
	int id,k,hp;
	bool operator<(const node&a)const{
		return a.hp<hp;
	}
};
vector<pii>v[maxn];
map<int,int>dis[maxn];
map<int,bool>vis[maxn];
int n,m,nn,s,t;
clock_t start, finish;
inline void dij()
{
	
	priority_queue<node>q;
	q.push({t,0,0});
	dis[t][0]=0;
	while(!q.empty())
	{
		auto [x,k,hp]=q.top();q.pop();
		// if((double(clock() - start) / CLOCKS_PER_SEC)>0.740){
		// 	cout<<1<<endl;
		// 	return ;
		// }
		if(x==s){
			cout<<hp<<endl;
			return ;
		}
		if(vis[x].count(k))continue;
		// cout<<x<<" "<<k<<" "<<hp<<endl;
		vis[x][k]=1;
		for(auto [y,w]:v[x])
		{
			int _k=k+1;
			int _hp=dis[x][k]+(w/_k);
			if(_k>nn)continue;
			if(!dis[y].count(_k)||dis[y][_k]>_hp)
			{
				dis[y][_k]=_hp;
				q.push({y,_k,dis[y][_k]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>s>>t;
	int flag=1;
	nn=n;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		if(w>1)flag=0;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	if(flag){
		// cout<<1<<endl;
		// return ;
		nn/=2;
	}
	dij();
	

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	start = clock();
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/