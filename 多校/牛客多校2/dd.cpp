/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct edge{
	int to,next;
	double w;
}edge[maxn];
double dis[maxn];
double ans[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],tot;
int stc[maxn],top,vis[maxn];
int n,m;
void add(int from,int to,double w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x)
{
	cout<<x<<endl;
	dfn[x]=low[x]=++tot;
	stc[++top]=x;//入栈
	vis[x]=1;

	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			//dis[y]=max(dis[y],dis[x]*edge[i].w);
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
		{
			if(dfn[y]<=low[x])
			{
				//ans[x]=dis[x];
				ans[x]=max(ans[x],dis[x]);
				if(x==3)cout<<y<<endl;
			}
			low[x]=min(low[x],dfn[y]);
		}
	}
	int y;
    if(dfn[x]==low[x])
    {
    	cout<<x<<endl;
        //集合数量++
        cnt++;
        do{
            y=stc[top--];
            //p[cnt].push_back(y);
            //col[y]=cnt;
            //涂色，标记相同集合
            vis[y]=0;
            //w[cnt]=min(w[cnt],y);
        }while(x!=y);//只要自己还没有弹出这个栈，都为同一个集合
    }
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		dis[i]=1;
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		add(b,d,1.0*c/a);
	}
	tarjan(1);
	double ma=1;
	for(int i=1;i<=n;i++)
		cout<<dfn[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<low[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		ma=max(ma,ans[i]);
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	printf("%.6lf",1.0/ma);
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5 6
1 1 2 3
1 1 2 2
2 2 1 4
1 4 2 1
1 3 3 4
1 3 2 5
*/