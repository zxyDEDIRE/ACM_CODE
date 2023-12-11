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
const int INF=1e14+7;
const int maxn=1e4+100;
struct node_1{string s;int x;};
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
bitset<maxn>vis;
bitset<maxn>ok;
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<node>q;

	q.push({s,0});
	dis[s]=0;
	
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	vector<node_1>ans;

	vector<int>q;
	q.push_back(n);
	ok[n]=1;
	while(1)
	{
		dij(n);

		int mi_1=0;
		int mi=INF;
		for(int i=1;i<=n;i++)
			if(!ok[i])mi=min(mi,dis[i]);
			else mi_1=max(mi_1,dis[i]);

		if(mi==INF){
			cout<<"inf"<<endl;
			return ;
		}

		string s="";
		for(int i=1;i<=n;i++)
			if(!ok[i])s=s+"1";
			else s=s+"0";

		ans.push_back({s,mi-mi_1});


		q.clear();
		for(int i=n;i>=1;i--)
			if(!ok[i]&&dis[i]==mi){
				q.push_back(i);
				ok[i]=1;
			}

		if(ok[1])break;
	}

	int sum=0;
	for(auto [s,x]:ans)
		sum+=x;

	cout<<sum<<" "<<ans.size()<<endl;
	for(auto [s,x]:ans)
		cout<<s<<" "<<x<<endl;

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
/*
6 5
6 5 1
6 4 1
3 5 10
3 4 7
1 3 9



*/