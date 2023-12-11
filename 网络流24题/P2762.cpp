/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*n);
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
	// cout<<"STEP "<<x<<" FLOW "<<flow<<endl;
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
	// cout<<x<<" "<<flow<<" "<<out<<endl;
	if(out==flow){
		dep[x]=0;
	}
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t)){
		// cout<<"yes"<<endl;
		ans+=dfs(s,INF,t);
	}
	return ans;
}

char tools[10000];
vector<int>v[maxn];
string str;
int id[maxn];
int a[maxn];
int b[maxn];
int h[maxn];
int w[maxn];
void solve()
{
	cin>>m>>n;
	int sum=0;
	tot=0;
	for(int i=1;i<=m;i++)
	{
		cin>>h[i];
		sum+=h[i];
		char tools[10000];
		memset(tools,0,sizeof tools);
		cin.getline(tools,10000);
		int ulen=0,tool;
		while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
		{//tool是该实验所需仪器的其中一个      
			v[i].push_back(tool);
		    //这一行，你可以将读进来的编号进行储存、处理，如连边。
			if (tool==0) 
				ulen++;
			else {
				while (tool) {
					tool/=10;
					ulen++;
				}
			}
			ulen++;
		}
		a[i]=++tot;
		id[tot]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
		b[i]=++tot;
		id[tot]=i;
	}
	s=++tot;
	t=++tot;
	init();
	for(int i=1;i<=m;i++)
	{
		add(s,a[i],h[i]);
		add(a[i],s,0);
	}
	for(int i=1;i<=n;i++)
	{
		add(b[i],t,w[i]);
		add(t,b[i],0);
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:v[i])
		{
			add(a[i],b[x],INF);
			add(b[x],a[i],0);
		}
	}
	int ans=sum-DINIC(s,t);
	for(int i=1;i<=m;i++)
		if(dep[i])
			cout<<i<<" ";cout<<endl;
	for(int i=m+1;i<=m+n;i++)
		if(dep[i])
			cout<<i-m<<" ";cout<<endl;
	cout<<ans<<endl;
}
signed main(){
 //freopen("C:\\Users\\tob\\Desktop\\P2762_2.in.txt","r",stdin);
 //freopen("C:\\Users\\tob\\Desktop\\P2762_2.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
 //fclose(stdin);
 //fclose(stdout);
	return 0;
}
/*
24 45
5 2 4 7 8 13 15 20 25
6 3
9 2 6 9 10 13 14 16 21 24 25
10 1 4 9 11 13 16
7 2 4 6 11 12 17 22 25 26 28
5 4
10 5
5 3 6 11 12 13 17
3 4
2 3 5 8 9 11
3 2 5 10
10 5 10 11 15 20 22 27 28 29 31
3 3 5 10 11 16 19 21 22
4 5 6 11 12 13 18 23
9 4 9 13 17 19
8 4 7 12 15 19 23 25 28
10 2 6 7 10 13 16 18
10 1 5
7 4 6
2 2 7 11 16
6 1 2 6 9 10 12 15 20 24
2 3 8 13 15 17 22
6 5 8 9 13 15 17 19 22 24
7 2 5 10 13 14 17
9 6 1 8 7 4 3 7 1 1 10 10 8 9 6 10 10 2 7 3 8 8 10 4 7 8 5 3 5 9 10 6 5 1 3 3 4 2 9 4 6 9 10 9 2

2 6 7 9 18 19 
1 3 4 5 6 
12



1 2
1000 1 2
1 1
*/