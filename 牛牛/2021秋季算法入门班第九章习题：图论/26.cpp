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
const int maxn=1e6;
struct node{
	int id;
	double dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next;double w;
}edge[maxn];
struct F{
	int x[5];
	int y[5];
}a[maxn];
int T[maxn];
int head[maxn],cnt;
int num[maxn][5],tot;
double dis[maxn];
bitset<maxn>vis;
int n,k,A,B,s,t;
void add(int from,int to,double w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int ds(int i,int x,int y)
{
	return (((a[i].x[x]-a[i].x[y])*(a[i].x[x]-a[i].x[y])+(a[i].y[x]-a[i].y[y])*(a[i].y[x]-a[i].y[y])));
}
int f(int i,int I,int j,int J)
{
	return (1.0*sqrt((a[i].x[I]-a[j].x[J])*(a[i].x[I]-a[j].x[J])+(a[i].y[I]-a[j].y[J])*(a[i].y[I]-a[j].y[J])));
}
void doit(int i)
{
	int d1=ds(i,1,2);
	int d2=ds(i,2,3);
	int d3=ds(i,1,3);
	if(d1==d2+d3)
	{
		int x=(a[i].x[1]+a[i].x[2])/2;
		int y=(a[i].y[1]+a[i].y[2])/2;
		int dx=x-a[i].x[3];
		int dy=y-a[i].y[3];
		a[i].x[4]=x+dx;
		a[i].y[4]=y+dy;
		add(num[i][1],num[i][3],1.0*sqrt(ds(i,1,3))*T[i]);
		add(num[i][3],num[i][1],1.0*sqrt(ds(i,1,3))*T[i]);

		add(num[i][2],num[i][3],1.0*sqrt(ds(i,2,3))*T[i]);
		add(num[i][3],num[i][2],1.0*sqrt(ds(i,2,3))*T[i]);

		add(num[i][4],num[i][1],1.0*sqrt(ds(i,1,4))*T[i]);
		add(num[i][1],num[i][4],1.0*sqrt(ds(i,1,4))*T[i]);

		add(num[i][4],num[i][2],1.0*sqrt(ds(i,2,4))*T[i]);
		add(num[i][2],num[i][4],1.0*sqrt(ds(i,2,4))*T[i]);
	}
	else if(d2==d1+d3)
	{
		int x=(a[i].x[3]+a[i].x[2])/2;
		int y=(a[i].y[3]+a[i].y[2])/2;
		int dx=x-a[i].x[1];
		int dy=y-a[i].y[1];
		a[i].x[4]=x+dx;
		a[i].y[4]=y+dy;
		add(num[i][2],num[i][1],1.0*sqrt(ds(i,1,2))*T[i]);
		add(num[i][1],num[i][2],1.0*sqrt(ds(i,1,2))*T[i]);

		add(num[i][1],num[i][3],1.0*sqrt(ds(i,1,3))*T[i]);
		add(num[i][3],num[i][1],1.0*sqrt(ds(i,1,3))*T[i]);

		add(num[i][4],num[i][2],1.0*sqrt(ds(i,2,4))*T[i]);
		add(num[i][2],num[i][4],1.0*sqrt(ds(i,2,4))*T[i]);

		add(num[i][4],num[i][3],1.0*sqrt(ds(i,3,4))*T[i]);
		add(num[i][3],num[i][4],1.0*sqrt(ds(i,3,4))*T[i]);
	}
	else if(d3==d1+d2)
	{
		int x=(a[i].x[1]+a[i].x[3])/2;
		int y=(a[i].y[1]+a[i].y[3])/2;
		int dx=x-a[i].x[2];
		int dy=y-a[i].y[2];
		a[i].x[4]=x+dx;
		a[i].y[4]=y+dy;
		add(num[i][2],num[i][3],1.0*sqrt(ds(i,2,3))*T[i]);
		add(num[i][3],num[i][2],1.0*sqrt(ds(i,2,3))*T[i]);

		add(num[i][2],num[i][1],1.0*sqrt(ds(i,2,1))*T[i]);
		add(num[i][1],num[i][2],1.0*sqrt(ds(i,2,1))*T[i]);

		add(num[i][4],num[i][1],1.0*sqrt(ds(i,1,4))*T[i]);
		add(num[i][1],num[i][4],1.0*sqrt(ds(i,1,4))*T[i]);

		add(num[i][4],num[i][3],1.0*sqrt(ds(i,3,4))*T[i]);
		add(num[i][3],num[i][4],1.0*sqrt(ds(i,3,4))*T[i]);
	}
}
void dij(int s,int t)
{
	for(int i=1;i<=tot;i++)
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
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n>>k>>A>>B;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
			num[i][j]=++tot;
		for(int j=1;j<=3;j++)
			cin>>a[i].x[j]>>a[i].y[j];
		cin>>T[i];
		doit(i);
	}
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int I=1;I<=4;I++)
			{
				for(int J=1;J<=4;J++)
				{
					add(num[i][I],num[j][J],1.0*f(i,I,j,J)*k);
					add(num[j][J],num[i][I],1.0*f(i,I,j,J)*k);
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
		add(s,num[A][i],0);
	for(int i=1;i<=4;i++)
		add(num[B][i],t,0);
	dij(s,t);
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
1
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
*/