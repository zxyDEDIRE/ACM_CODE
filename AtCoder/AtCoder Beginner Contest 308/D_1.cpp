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
const int maxn=1e6+100;
const int N=555;
map<char,int>mp;
vector<int>v[maxn];
bitset<maxn>vis;
int p[N][N];
int n,m;
int f(int x,int y)
{
	return x*(n+1)+y;
}
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	for(auto y:v[x])
	{
		dfs(y);
	}
}
void solve()
{
	mp['s']=0;
	mp['n']=1;
	mp['u']=2;
	mp['k']=3;
	mp['e']=4;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			p[i][j]=mp[ch];
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int xx=i+dx[k];
				int yy=j+dy[k];
				if(xx<1||yy<1||xx>n||yy>m)continue;
				if((p[i][j]+1)%5!=p[xx][yy])continue;
				v[f(i,j)].push_back(f(xx,yy));
			}
		}
	}
	dfs(f(1,1));
	if(!vis[f(n,m)])cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}