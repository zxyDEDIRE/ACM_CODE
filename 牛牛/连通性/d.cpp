#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
// #define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int mod=998244353;
int head[N],cnt;
int low[N],dfn[N],idx;
int RES=1e9;
struct Edge
{
	int to,next;
}e[N];
void add(int from,int to)
{
	e[++cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt;
}
int sta,en;
int ans[N];
void tarjan(int x,int fa)
{
	cout<<x<<endl;
	dfn[x]=low[x]=++idx;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(!dfn[y]){
			tarjan(y,fa);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=fa&&dfn[x]<=dfn[en])
			{
				if(x!=fa&&x!=en)RES=min(RES,x);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int n;
void solve()
{
	cin>>n;
	int x,y;
	while(cin>>x>>y&&x){
		add(x,y);
		add(y,x);
	}
	cin>>sta>>en;
	tarjan(sta,sta);
	for(int i=1;i<=n;i++)
		cout<<dfn[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<low[i]<<" ";cout<<endl;
	if(RES==1e9)cout<<"No solution"<<endl;
	else cout<<RES<<endl;
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}
/*
4
1 3
1 2
2 4
2 3
0 0
1 3


4
1 2
1 3
2 4
2 3
0 0
1 3


5
1 3
1 2
2 4
2 5
5 3
0 0
1 3
*/