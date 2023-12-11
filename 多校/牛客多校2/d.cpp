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
using ld=long double;
using pii=pair<int,int>;
const int maxn=1e6;
const ld I=1.0;
struct Edge{
	int to,next;
	double w;
}edge[maxn];
int head[maxn],cnt;
double dis[maxn];
int n;
void add(int from,int to,double w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		add(b,d,I*c/a);
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}