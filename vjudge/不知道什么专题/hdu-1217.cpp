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
const int maxn=100;
struct Edge{
	int x,y;
	double w;
}edge[maxn<<4];
int head[maxn],cnt;
map<string,int>mp;
double dis[maxn];
bitset<maxn>vis;
int n,m;
void YES(){cout<<"Yes"<<endl;}
void NO(){cout<<"No"<<endl;}
void add(int from,int to,double w,int x)
{
	edge[x].x=from;
	edge[x].y=to;
	edge[x].w=w;
}
bool dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=0;
	dis[s]=1;
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=m;j++)
		{
			if(dis[edge[j].y]<dis[edge[j].x]*edge[j].w)
			{
				dis[edge[j].y]=dis[edge[j].x]*edge[j].w;
				flag=0;
			}
		}
		if(flag)break;
	}
	for(int i=1;i<=m;i++)
	{
		if(dis[edge[i].y]<dis[edge[i].x]*edge[i].w)
		{
			return 1;
		}
	}
	return 0;
}
void solve()
{
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		mp[str]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string a,b;
		double x;
		cin>>a>>x>>b;
		add(mp[a],mp[b],x,i);
	}
	for(int i=1;i<=n;i++)
		if(dij(i))return YES();
	return NO();
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int __=1;
	while(cin>>n){
		if(n==0)break;
		cout<<"Case "<<__++<<": ";
		solve();
	}
	return 0;
}


/*
Case 1: Yes
Case 2: No
Case 1: Yes
Case 2: No

0.5*10.0*0.21

3
USDollar
BritishPound
FrenchFranc
3
FrenchFranc 0.21 USDollar
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc


*/