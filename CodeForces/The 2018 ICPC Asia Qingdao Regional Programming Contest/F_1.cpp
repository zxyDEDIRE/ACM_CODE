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
const int N=3111;
bool _x[N][N];
bool vis[N];
int P[maxn][15];
int p[maxn];
vector<int>ans;
int w[maxn];
int n,m,cnt;
void dfs(int step)
{
	if(step==n){
		// for(int i=1;i<n;i++)
		// 	cout<<w[i]<<" ";cout<<endl;
		for(int i=1;i<n;i++)
		{
			int x=w[i];
			for(int j=1;j<=n;j++)
				cout<<P[x][j]<<" ";cout<<endl;
		}
		return ;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(vis[i])continue;
		int ok=1;
		for(int j=1;j<=n;j++)
			if(_x[j][P[i][j]])ok=0;
		if(ok==0)continue;



		vis[i]=1;
		for(int j=1;j<=n;j++)
			_x[j][P[i][j]]=1;

		w[step]=i;

		dfs(step+1);

		vis[i]=0;
		for(int j=1;j<=n;j++)
			_x[j][P[i][j]]=1;


	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		cnt++;
		int ok=0;
		// for(int i=1;i<=n;i++)
		// 	P[cnt][i]=p[i];
		for(int i=1;i<=n;i++)
		{
			int x=i;
			int y=p[i];
			if(p[x]!=y||p[y]!=x)ok=1;
		}
		cnt-=ok;
		cout<<cnt<<endl;
	}while(next_permutation(p+1,p+1+n));
	// cout<<cnt<<endl;
	// cout<<cnt<<endl; 
	// for(int i=1;i<=n;i++)
	// 	_x[i][i]=1;
	// dfs(1);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}