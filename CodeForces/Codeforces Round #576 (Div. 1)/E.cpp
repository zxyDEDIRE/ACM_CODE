/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
	int x1,y1,x2,y2;
}p[100];
vector<int>xx,yy;
int inx[111];
int iny[111];
pii x[111];
pii y[111];
int lenx,leny;
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
		p[i].x2++;
		p[i].y2++;
		xx.push_back(p[i].x1);
		xx.push_back(p[i].x2);
		yy.push_back(p[i].y1);
		yy.push_back(p[i].y2);
	}
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	lenx = unique(xx.begin(), xx.end()) - xx.begin();
	leny = unique(yy.begin(), yy.end()) - yy.begin();
	s=++tot;
	t=++tot;
	for(int i=1;i<lenx;i++)
	{
		inx[i]=++tot;
		x[i]={xx[i-1],xx[i]};
		add(s,inx[i],xx[i]-xx[i-1]);
		add(inx[i],s,0);
	}
	for(int i=1;i<leny;i++)
	{
		iny[i]=++tot;
		y[i]={yy[i-1],yy[i]};
		add(iny[i],t,yy[i]-yy[i-1]);
		add(t,iny[i],0);
	}
	lenx--;
	leny--;
	for(int I=1;I<=m;I++)
	{
		auto [x1,y1,x2,y2]=p[I];
		for(int i=1;i<=lenx;i++)
		{
			for(int j=1;j<=leny;j++)
			{
				if(x1<=x[i].first&&x2>=x[i].second&&y1<=y[j].first&&y2>=y[j].second)
				{
					add(inx[i],iny[j],INF);
					add(iny[j],inx[i],0);
				}
			}
		}
	}
	cout<<DINIC(s,t)<<endl;
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
10 3
4 1 10 1
3 1 10 1
2 1 4 1
*/