/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
int p[maxn];
int n,m,s,t;
int find(int r){return p[r]=(p[r]==r)?p[r]:find(p[r]);}
void init(){for(int i=1;i<=n;i++)p[i]=i;}
void un(int x,int y){
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)p[fa]=fb;
}
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=from;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		un(x,y);
	}
	cin>>s>>t;
	if(find(s)!=find(t)){
		cout<<"IMPOSSIBLE"<<endl;
		return ;
	}
	sort(edge+1,edge+1+cnt,cmp);
	double ans=1e9;
	int ma=1e9,mi=1e9;
	for(int i=1;i<=m;i++)
	{
		init();
		for(int j=i;j<=m;j++)
		{
			un(edge[j].next,edge[j].to);
			if(find(s)==find(t))
			{
				if((1.0*edge[j].w/edge[i].w)<ans)
				{
					ans=1.0*edge[j].w/edge[i].w;
					ma=edge[j].w;
					mi=edge[i].w;
				}
			}
		}
	}
	//cout<<ans<<endl;
	int x=ma/__gcd(ma,mi);
	int y=mi/__gcd(ma,mi);
	if(y==1)cout<<x<<endl;
	else cout<<x<<"/"<<y<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}