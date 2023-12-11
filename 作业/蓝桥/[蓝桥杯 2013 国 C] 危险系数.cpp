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
vector<int>v[maxn];
bitset<2000>vis;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int s,t;
	cin>>s>>t;
	int cnt=0;

	auto bfs=[&](int s,int t,int k)->int{
		queue<int>q;
		q.push(s);
		vis.reset();
		vis[s]=1;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(x==t)return 0;
			for(auto y:v[x])
				if(!vis[y]&&y!=k)
					vis[y]=1,q.push(y);
		}
		return 1;
	};

	if(bfs(s,t,-1)==1){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==s||i==t)continue;
		int x=bfs(s,t,i);
		if(x==1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
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