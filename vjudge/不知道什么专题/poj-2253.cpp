/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<queue>
#include<bitset>
#include<cmath>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
typedef pair<int,int> pii ;
struct node{
	int id;
	double dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(int a,int b):id(a),dis(b){};
};
double dis[maxn];
bitset<maxn>vis;
pii p[maxn];
int n;
double f(int x,int y){
	return (p[x].first-p[y].first)*(p[x].first-p[y].first)+(p[x].second-p[y].second)*(p[x].second-p[y].second);
}
void dij(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>max(f(i,x),dis[x]))
			{
				dis[i]=max(f(i,x),dis[x]);
				q.push(node(i,dis[i]));
			}
		}
	}
	printf("%.3lf\n\n",sqrt(dis[t]));
}
void solve()
{
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	cout<<"Frog Distance = ";
	dij(1,2);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_witstdio(false);
	// cin.tie(nullptrh_);cout.tie(nullptr);
	int cnt=1;
	while(cin>>n&&n){
		cout<<"Scenario #"<<cnt++<<endl;

		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}