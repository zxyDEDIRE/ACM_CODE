/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6+100;
const int N=2222;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
vector<int>v[N][N];
pii a1[maxn],a2[maxn];
pii b1[maxn],b2[maxn];
int s,t,tot;
int n,m;
void init(){
	for(int i=0;i<=2000;i++)
		for(int j=0;j<=2000;j++)
			v[i][j].clear();
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*tot);
	queue<int>q;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dep[y]==0&&w>0)
				q.push(y),dep[y]=dep[x]+1;
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
int in1[maxn];
int in2[maxn];
void solve()
{
	init();
	cin>>n>>m;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		in1[i]=++tot;
		// cout<<"I "<<i<<" id "<<in1[i]<<endl;
		add(in1[i],t,1);
		add(t,in1[i],0);
		cin>>a1[i].first>>a1[i].second>>a2[i].first>>a2[i].second;
		for(int x=a1[i].first;x<=a2[i].first;x++)
			for(int y=a1[i].second;y<=a2[i].second;y++)
				v[x][y].push_back(i);
	}
	int x,y,xx,yy;
	auto check=[&](int i)->bool{
		// cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
		// cout<<a1[i].first<<" "<<a1[i].second<<" "<<a2[i].first<<" "<<a2[i].second<<endl;
		int x1=max(x,a1[i].first);
		int x2=min(xx,a2[i].first);
		int y1=max(y,a1[i].second);
		int y2=min(yy,a2[i].second);
		// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		int S1=(a2[i].first-a1[i].first)*(a2[i].second-a1[i].second);
		int S2=(x2-x1)*(y2-y1);
		// cout<<S1<<" "<<S2<<endl;
		// cout<<(2*S2>=S1)<<endl;
		// cout<<endl;
		if(x1>=x2||y1>=y2)return 0;
		return 2*S2>=S1;
	};
	for(int i=1;i<=m;i++)
	{
		in2[i]=++tot;
		// cout<<"J "<<i<<" id "<<in2[i]<<endl;
		add(s,in2[i],1);
		add(in2[i],s,0);
		cin>>x>>y>>xx>>yy;
		map<int,bool>mp;
		for(int dx=x;dx<=xx;dx++)
			for(int dy=y;dy<=yy;dy++)
				for(auto j:v[dx][dy])
					if(check(j)==1&&!mp.count(j)){
						add(in2[i],in1[j],1);
						add(in1[j],in2[i],0);
						// cout<<"edge "<<in2[i]<<" "<<in1[j]<<endl;
						mp[j]=1;
					}
	}
	cout<<DINIC(s,t)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 2
1 1 3 3
3 3 5 5
2 2 4 4
4 4 6 6

*/