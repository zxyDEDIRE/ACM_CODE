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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
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
struct node{
	int x,y,z;
}p[maxn];
vector<int>v[111];
vector<int>a,b;
bool su(int x)
{
	if(x==1)return 0;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	int tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
void doit()
{
	for(int i=1;i<=n;i++)
		if(p[i].y&1)a.push_back(i);
		else b.push_back(i);
	for(auto i:a)
	{
		for(auto j:b)
		{
			if(su(p[i].y+p[j].y))
				v[i].push_back(j);
		}
	}
}
bool check(int mid)
{
	init();
	tot=n;
	s=++tot;
	t=++tot;
	int sum=0;
	for(auto i:a)
		if(p[i].z<=mid){

			sum+=p[i].x;

			add(s,i,p[i].x);
			add(i,s,0);

			for(auto j:v[i])
				if(p[j].z<=mid){
					add(i,j,INF);
					add(j,i,0);
				}
		}
	for(auto i:b)
		if(p[i].z<=mid){
			sum+=p[i].x;

			add(i,t,p[i].x);
			add(t,i,0);
		}
	int ans=DINIC(s,t);
	if(sum-ans>=m)return true;
	else return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y>>p[i].z;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.z<b.z;
	});

	doit();
	
	int l=1,r=p[n].z,ma=r,ans=r;

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(p[i].y==1)cnt++;
		else break;
	for(int i=1;i<cnt;i++)
		p[i].z=INF;

	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(!check(ma)){
		cout<<-1<<endl;
		return ;
	}
	if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
5 8
5 5 1
1 5 4
4 6 3
1 12 4
3 12 1
*/