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
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
const int N=100000;
int dis[maxn];
void bfs(int s,int t)
{
	for(int i=0;i<=100000;i++)
		dis[i]=INF;
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(x==t){
			cout<<DIS<<endl;
			return ;
		}
		if(x*2<=N&&dis[x*2]>dis[x]+1)
		{
			dis[x*2]=dis[x]+1;
			q.push({x*2,dis[x*2]});
		}
		if(x+1<=N&&dis[x+1]>dis[x]+1)
		{
			dis[x+1]=dis[x]+1;
			q.push({x+1,dis[x+1]});
		}
		if(x-1>=0&&dis[x-1]>dis[x]+1)
		{
			dis[x-1]=dis[x]+1;
			q.push({x-1,dis[x-1]});
		}
	}
}
void solve()
{
	int n,k;
	cin>>n>>k;
	bfs(n,k);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}