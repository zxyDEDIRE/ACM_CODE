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
vector<vector<int>>d={{0,1,0,2},{1,0,2,0},{1,-1,2,-2},{0,-1,0,-2},{-1,-1,-2,-2},{-1,0,-2,0}};
int L[]={0,3,4,5,4,3,0};
int mp[6][6];
int ans=0;
struct node{
	bool a[6][6];
	bool operator<(const node&A)const{
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
				if(A.a[i][j]!=a[i][j])
					return A.a[i][j]>a[i][j];
		return 1;
	}
};
map<node,bool>vis;
void dfs(node x,int sum)
{
	if(vis[x])return;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=L[i];j++)
			cout<<x.a[i][j];
		cout<<endl;
	}
	cout<<sum<<endl;
	cout<<endl;


	// _sleep(500);
	ans=max(ans,sum);
	vis[x]=1;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=L[i];j++)
		{
			if(!x.a[i][j])continue;
			for(auto k:d)
			{
				int x1=i+k[0];
				int y1=j+k[1];
				int x2=i+k[2];
				int y2=j+k[3];
				if(x1<1||x1>5||x2<1||x2>5)continue;
				if(y1<1||y1>L[x1]||y2<1||y2>L[x2])continue;
				if(!x.a[x1][y1])continue;
				if(x.a[x2][y2])continue;
				node now=x;
				now.a[i][j]=now.a[x1][y1]=0;
				now.a[x2][y2]=1;
				dfs(now,sum+mp[x1][y1]);
			}
		}
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=L[i];j++)
		{
			if(!x.a[i][j])continue;
			node now=x;
			now.a[i][j]=0;
			dfs(now,sum);
		}
	}
}
void solve()
{
	node st;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=L[i];j++){
			char ch;cin>>ch;
			if(ch=='#')st.a[i][j]=1;
			else st.a[i][j]=0;
		}
	ans=0;
	vis.clear();
	dfs(st,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	for(int i=1;i<=5;i++)
		for(int j=1;j<=L[i];j++)
			cin>>mp[i][j];
	int n;
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
/*
  9 2 2
 3 3 7 2
0 3 6 8 5
 4 7 7 5
  8 0 7

9 2 2
3 3 7 2
0 3 6 8 5
4 7 7 5
8 0 7
1
...
..#.
..##.
....
...
*/