/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int x,w;
	bool operator<(const node&a)const{
		return a.w<w;
	}
};
struct E{
	int x,y,w;
}p[maxn];
bitset<maxn>vis;
int n;
int dij(int s)
{
	vis.reset();
	int ma=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,D]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		ma=max(ma,D);
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			int tmp=(abs(p[x].x-p[i].x)+abs(p[x].y-p[i].y)+p[x].w-1)/p[x].w;
			q.push({i,tmp});
		}
	}
	return ma;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y>>p[i].w;
	int mi=INF;
	for(int i=1;i<=n;i++)
		mi=min(mi,dij(i));
	cout<<mi<<endl;
	// cout<<dij(2)<<endl;
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
/*
4
-10 0 1
0 0 5
10 0 1//10
11 0 1//
*/