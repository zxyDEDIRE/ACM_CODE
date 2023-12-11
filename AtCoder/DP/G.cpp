/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis>dis;
	}
};
vector<int>v[maxn];
int dis[maxn];
int in[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push({i,0});
	int ma=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();
		ma=max(ma,DIS);
		q.pop();
		for(auto y:v[x])
		{
			dis[y]=max(dis[y],dis[x]+1);
			in[y]--;
			if(!in[y])
				q.push({y,dis[y]});
		} 
	}
	cout<<ma<<endl;
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