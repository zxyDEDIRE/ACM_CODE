#include<bits/stdc++.h>
using namespace std;
struct{
    int nxt,mark,v;
}pre[2010];
int n,m,cnt;
bool vis[110];
int dis[110];
int head[110];
int in[110];
int t;
void add (int x,int y,int v,int w)
{
	pre[w].mark=head[x];
	pre[w].nxt=y;
	pre[w].v=v;
	head[x]=w;
}
bool check ()
{
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while (!q.empty())
    {
        int x=q.front(); q.pop();
		vis[x]=0;
	//	cout<<x<<endl;
        for (int i=head[x];i!=0;i=pre[i].mark)
        {
            int y=pre[i].nxt;
            int l=pre[i].v;
            if (dis[y]>dis[x]+l)
            {
                dis[y]=dis[x]+l;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y]=1;
                    in[y]++;if (in[y]>=n)return 0;
                }
        	}
		}
    }
    return 1;
}
int main()
{
    scanf ("%d",&t);
    while (t--)
    {
        memset (head,0,sizeof (head));
        memset (vis,0,sizeof (vis));
        memset (dis,0,sizeof (dis));
        memset (in,0,sizeof (in));
        scanf ("%d%d",&n,&m);
        cnt=0;
        for(int i=1;i<=n;i++)add(0,i,0,++cnt);
        for (int i=1;i<=m;i++)
        {
            int s,e,v;
            scanf ("%d%d%d",&s,&e,&v);
            add (s-1,e,-v,++cnt);
            add (e,s-1,v,++cnt);
        }
        if (check ())
            printf ("true\n");
        else
            printf ("false\n");
    }
}
