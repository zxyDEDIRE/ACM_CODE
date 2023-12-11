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
const int maxn=1e6+100;
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
bitset<maxn>vis,ok;
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}

void dij(vector<int>&p)
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	for(auto s:p)
	{
		dis[s]=0;
		q.push({s,0});
	}
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(!ok[y])continue;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	ok.reset();
	for(int i=1;i<=n;i++)ok[i]=1;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	
	vector<string>ans_1;
	vector<int>ans_2;
	vector<int>q;

	q.push_back(n);
	ok[n]=0;
	while(1)
	{
		dij(q);
		int mi=INF;
		int flag=1;
		for(int i=1;i<=n;i++){
			if(ok[i])
				mi=min(mi,dis[i]);
			if(dis[i])flag=0;
		}

		if(mi==INF){
			cout<<"inf"<<endl;
			return ;
		}
		
		string str="";
		for(int i=1;i<=n;i++)
			if(ok[i])str=str+"1";
			else str=str+"0";

		q.clear();
		for(int i=1;i<=n;i++)
			if(dis[i]==mi&&ok[i])
				q.push_back(i),ok[i]=0;

		ans_1.push_back(str);
		ans_2.push_back(mi);
		
		if(ok[1]==0)break;
	}
	int sum=accumulate(ans_2.begin(),ans_2.end(),0ll);
	cout<<sum<<" "<<ans_2.size()<<endl;
	for(int i=0;i<ans_2.size();i++)
	{
		cout<<ans_1[i]<<" "<<ans_2[i]<<endl;
	}
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
*/