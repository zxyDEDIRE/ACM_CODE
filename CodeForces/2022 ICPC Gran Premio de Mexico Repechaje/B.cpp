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
const int N=111;
bitset<N>vis[N];
int mp[N][N];
bool cnt[11];
bool ok[N];
int sx,sy;
int tx,ty;
int n,m;
bool bfs()
{
	if(!ok[mp[sx][sy]])return false;
	for(int i=1;i<=n;i++)
		vis[i].reset();
	queue<pii>q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(x==tx&&y==ty)return true;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||!ok[mp[xx][yy]])continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	return false;
}
void solve()
{
	cin>>n>>m>>sx>>sy>>tx>>ty;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j],cnt[mp[i][j]]=true;
	int mi=10;
	for(int i=0;i<(1<<10);i++)
	{
		int num=0;
		for(int j=1;j<=10;j++)
		{
			if(i&(1<<(j-1)))ok[j]=1,num++;
			else ok[j]=0;

			if((i&(1<<(j-1)))&&(!cnt[j])){
				memset(ok,0,sizeof(ok));
				break;
			}
		}
		if(bfs())mi=min(mi,num);
	}
	cout<<mi<<endl;
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