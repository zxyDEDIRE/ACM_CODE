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
		return a.dis<dis;
	}
};
bitset<maxn>vis;
int dis[1000];
int n=300;
void init()
{
	for(int i=11;i<=300;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push({10,0});
	dis[10]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		if(x+1<=300 && dis[x+1]>dis[x]+1)
		{
			dis[x+1]=dis[x]+1;
			q.push({x+1,dis[x+1]});
		}
		if(x-1>=10 && dis[x-1]>dis[x]+1)
		{
			dis[x-1]=dis[x]+1;
			q.push({x-1,dis[x-1]});
		}
		if(x+10<=300 && dis[x+10]>dis[x]+1)
		{
			dis[x+10]=dis[x]+1;
			q.push({x+10,dis[x+10]});
		}
		if(x-10>=10 && dis[x-10]>dis[x]+1)
		{
			dis[x-10]=dis[x]+1;
			q.push({x-10,dis[x-10]});
		}
		if(x+100<=300 && dis[x+100]>dis[x]+1)
		{
			dis[x+100]=dis[x]+1;
			q.push({x+100,dis[x+100]});
		}
		if(x-100>=10 && dis[x-100]>dis[x]+1)
		{
			dis[x-100]=dis[x]+1;
			q.push({x-100,dis[x-100]});
		}
		if(dis[300]>dis[x])
		{
			dis[300]=dis[x]+1;
			q.push({300,dis[300]});
		}
	}
}
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(dis[a]+dis[b]+dis[c]+dis[d])<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}