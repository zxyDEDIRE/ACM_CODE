/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int prime[maxn];
bool vis[maxn];
void init()
{
	for(int i=2;i<=1e5;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=1e5;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.y<y;
	}
};
void solve()
{
	int n,m;
	cin>>n>>m;


	priority_queue<node>q;
	q.push({n,0});
	while(!q.empty())
	{
		auto [x,step]=q.top();q.pop();
		for(int i=1;i<=4;i++)
		{
			
		}
	}
}
signed main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
1021 1409
*/