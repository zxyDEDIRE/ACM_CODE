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
	dij(n);
	if(dis[1]==INF){cout<<"inf"<<endl;return ;}
	vector<int>s;
	for(int i=1;i<=n;i++)
		s.push_back(dis[i]);
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	vector<pair<string,int>>ans;
	int cnt=0,sum=0;
	for(int i=1;i<s.size();i++)
	{
		int x=s[i];
		int y=s[i-1];
		string str="";
		for(int j=1;j<=n;j++)
			if(dis[j]>=x)str=str+"1"; 
			else str=str+"0";
		if(str[0]=='0')break;
		ans.push_back({str,x-y});
		sum+=x-y;
	}
	cout<<sum<<" "<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<endl;
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