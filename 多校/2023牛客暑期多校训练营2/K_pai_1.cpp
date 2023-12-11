/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6+100;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
int MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	// cout<<maxf<<" "<<maxc<<endl;
	// cout<<-maxc<<endl;
	return -maxc;
}
int a[maxn];
int b[maxn];
int solve()
{
	init();
	s=n*2+1;
	t=n*2+2;
	tot=t;
	for(int i=1;i<=n;i++)
	{
		add(i*2,t,1,-a[i]);
		add(t,i*2,0,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x=b[i];
		if(x==0)continue;
		add(s,i,1,0);
		add(i,s,0,0);


		add(i,i*2,1,0);
		add(i*2,i,0,0);
		if(i-1>=1)
		{
			add(i,(i-1)*2,1,0);
			add((i-1)*2,i,0,0);
		}
		if(i+1<=n)
		{
			add(i,(i+1)*2,1,0);
			add((i+1)*2,i,0,0);
		}
	}
	return MCMF(s,t);
}
long long dp[maxn][6];
int XTC()
{
	for(int i=1;i<=n;i++)
    {
        if(b[i]==1)
        {
            if(b[i-1]==1)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][2])+a[i];
                dp[i][2]=dp[i-1][2];
                dp[i][3]=max({dp[i-1][3]+a[i],dp[i-1][0]});
                dp[i][4]=dp[i-1][3]+a[i];
                if(b[i+1]==1)
                {
                    dp[i][5]=dp[i-1][5]+a[i];
                }
            }
            else{
                //0自己拿自己 1一开始没有 2自己有被前面拿了
                //3被后面拿了 4拿了前面 5拿了后面 
                dp[i][0]=max(dp[i-1][1],dp[i-1][4])+a[i];
                dp[i][2]=dp[i-1][1];
                dp[i][3]=max(dp[i-1][4],dp[i-1][1]);
                if(b[i+1]==1)
                {
                    dp[i][5]=dp[i-1][5]+a[i];
                }
            }
        }
        else{
            //0自己拿自己 1一开始没有 2自己有被前面拿了
            //3被后面拿了 4拿了前面 5拿了后面 
            if(b[i-1]==1)
            {
                dp[i][1]=max(dp[i-1][2],dp[i-1][0]);
                dp[i][4]=max(dp[i-1][4],dp[i-1][3])+a[i];
                if(b[i+1]==1)
                {
                    dp[i][5]=max(dp[i-1][0],dp[i-1][2])+a[i];
                }
            }
            else{
                dp[i][1]=max(dp[i-1][1],dp[i-1][4]);                
                if(b[i+1]==1)
                {
                    dp[i][5]=max(dp[i-1][1],dp[i-1][4])+a[i];
                }
            }
        }
    }
    return max({dp[n][0],dp[n][1],dp[n][2],dp[n][3],dp[n][4],dp[n][5]});
}
signed main(){
	srand(time(0));
	while(true)
	{
		n=rand()%4+1;
		for(int i=1;i<=n;i++)
			a[i]=rand()%100;
		for(int i=1;i<=n;i++)
			b[i]=rand()%2;
		int ans_1=solve();
		int ans_2=XTC();
		if(ans_1!=ans_2)
		{
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";cout<<endl;
			for(int i=1;i<=n;i++)
				cout<<b[i]<<" ";cout<<endl;
			return 0;
		}
	}


	return 0;
}