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
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=32;
struct node{
	int a,b,c,d;
}p[maxn];
bool vis[maxn][maxn];
int sx,sy,tx,ty;
int n,m,k;
bool bfs()
{
	queue<pii>q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(x==tx&&y==ty)return 1;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0||yy<0||xx>n||yy>m||vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	return 0;
}
bool check(int K)
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<k;i++)
	{
		if(K&(1<<i))
		{
			auto [a,b,c,d]=p[i];
			a*=2;b*=2;c*=2;d*=2;
			if(a==c)
			{
				if(b>d)swap(b,d);
				for(int j=max(0,b-1);j<=min(m,d+1);j++)
					vis[a][j]=1;
			}
			else
			{
				if(a>c)swap(a,c);
				for(int j=max(0,a-1);j<=min(n,c+1);j++)
					vis[j][b]=1;
			}
		}
	}
	return bfs();
}
void solve()
{
	cin>>n>>m>>k;
	n*=2,m*=2;
	cin>>sx>>sy>>tx>>ty;
	sx=sx*2+1;sy=sy*2+1;tx=tx*2+1;ty=ty*2+1;
	for(int i=0;i<k;i++)
	{
		cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d;
	}
	int ans=0;
	for(int i=(1<<k)-1;i>=0;i--)
	{
		if(check(i)){
			ans=i;
			break;
		}
	}
	int cnt=0;
	while(ans){
		if(ans&1)cnt++;
		ans>>=1;
	}
	cout<<k-cnt<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}