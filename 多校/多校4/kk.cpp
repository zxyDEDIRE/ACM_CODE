/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int n,ans,tmp;
int flag=0;
void bfs(int xx,int y)
{
	queue<pii>q;
	q.push({xx,0ll});
	while(!q.empty())
	{
		auto [x,step]=q.front();q.pop();
		if((x%n)==(y%n)){
			ans+=step;
			cout<<step<<endl;
			tmp=x;
			return ;
		}
		for(int i=0;i<=9;i++)
			q.push({x*10+i,step+1});
	}
}
void solve()
{
	int x,y;
	cin>>n;
	tmp=0;
	for(int i=1;i<=n;i++)
	{
		cout<<tmp<<" "<<i<<endl;
		bfs(tmp,i);
	}
	//bfs(x,y);
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
17
6 7
*/