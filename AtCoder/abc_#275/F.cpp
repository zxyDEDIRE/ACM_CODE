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
const int maxn=1e5+100;
int num[maxn][40][2];
bitset<40>f[maxn];
bitset<maxn>vis;
int fa[maxn];
int n,m,flag;
int find(int r){
	return fa[r]=fa[r]==r?fa[r]:find(fa[r]);
}
void un(int X,int Y){
	int x=find(X);
	int y=find(Y);
	if(x!=y)
	{
		fa[y]=x;
		for(int i=0;i<=31;i++)
		{
			num[x][i][0]+=num[y][i][0];
			num[x][i][1]+=num[y][i][1];
		}
	}
}
void add(int x)
{
	for(int i=0;i<=31;i++)
	{
		if(f[x][i])num[x][i][1]++;
		else num[x][i][0]++;
	}
}
void doit(int x,int y,int w)
{
	for(int i=31;i>=0;i--)
	{
		if(w>=(1ll<<i))
		{
			w-=(1ll<<i);
			f[y][i]=(f[x][i]^1);
		}
		else
			f[y][i]=f[x][i];
	}
	if(!vis[x]){
		add(x);
		vis[x]=1;
	}
	if(!vis[y]){
		add(y);
		vis[y]=1;
	}
}
void check(int x,int y,int w)
{
	for(int i=31;i>=0;i--)
	{
		if(w>=(1ll<<i))
		{
			w-=(1ll<<i);
			if(f[x][i]==f[y][i])flag=1;
		}
		else if(f[x][i]!=f[y][i])flag=1;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	flag=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		
		x=find(x);
		y=find(y);
		if(!vis[x])swap(x,y);
		if(!vis[y])doit(x,y,w);
		else check(x,y,w);
		un(x,y);
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<f[i]<<endl;
	if(flag)
	{
		cout<<-1<<endl;
		return ;
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	int x=find(i);
	// 	for(int j=31;j>=0;j--)
	// 	{
	// 		if(f[i][j]==1)num[x][j][1]++;
	// 		else num[x][j][0]++;
	// 	}
	// }
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(find(i)!=i)continue;
		for(int j=31;j>=0;j--)
		{
			int x=num[i][j][0];
			int y=num[i][j][1];
			if(x>y)swap(x,y);
			ans+=x*(1ll<<j);
		}
	}
	cout<<ans<<endl;
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
000
000
011
100

9
5
1 3 1 
2 4 9 
2 9 0
6 8 1
6 7 12


*/