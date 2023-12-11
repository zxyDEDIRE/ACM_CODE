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
const int N=666;
vector<int>v[maxn];
double p[maxn];
int mp[N][N];
int in[maxn];
int out[maxn];
int n,m;
int f(int x,int y){
	return (x-1)*n+y;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mp[i][j]),p[f(i,j)]=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||x>n||y<1||y>n)continue;
				if(mp[x][y]>=mp[i][j])continue;
				v[f(i,j)].push_back(f(x,y));
				in[f(x,y)]++;
				out[f(i,j)]++;
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=n*n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			p[y]+=1.0*p[x]/out[x];
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(mp[i][j]==0)printf("%.6f ",p[f(i,j)]);
			else printf("0 ");
		printf("\n");
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}