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
const int N=2222;
char mp[N][N];
int vis[N][N];
int ok[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	while(1)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;set<char>s;
			for(int j=1;j<=m;j++)
			{
				if(ok[i][j])continue;
				s.insert(mp[i][j]);cnt++;
			}
			if(s.size()==1&&cnt>=2)
			{
				flag=1;
				for(int j=1;j<=m;j++)
					vis[i][j]=1;
			}
		}


		for(int j=1;j<=m;j++)
		{
			int cnt=0;set<char>s;
			for(int i=1;i<=n;i++)
			{
				if(ok[i][j])continue;
				s.insert(mp[i][j]);cnt++;
			}
			if(s.size()==1&&cnt>=2)
			{
				flag=1;
				for(int i=1;i<=n;i++)
					vis[i][j]=1;
			}
		}

		if(!flag)break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ok[i][j]|=vis[i][j];
	}

	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j])cnt++;
		cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}