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
const int N=5e3;
struct Node{
	int id,dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
bitset<N>vis,ok;
struct node{
	int x,a,b;
}p[N];
int dis[N];
int n,len,m;
string X;
int f(string a)
{
	reverse(a.begin(),a.end());
	int now=0;
	for(int i=0;i<a.size();i++)
		if(a[i]=='1')
			now+=pow(2,i);
	return now;
}
void dij(int s)
{
	priority_queue<Node>q;
	vis.reset();
	ok.reset();
	dis[s]=0;
	q.push({s,0});
	ok[s]=1;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			int now=(x^(p[i].a&x));
			now|=p[i].b;
			if(!ok[now])dis[now]=INF,ok[now]=1;
			if(dis[now]>dis[x]+p[i].x)
			{
				dis[now]=dis[x]+p[i].x;
				q.push({now,dis[now]});
			}
		}
	}
	if(!ok[0])cout<<-1<<endl;
	else cout<<dis[0]<<endl;
}
void solve()
{
	cin>>len>>n>>X;
	m=f(X);
	for(int i=1;i<=n;i++){
		cin>>p[i].x;
		cin>>X;
		p[i].a=f(X);
		cin>>X;
		p[i].b=f(X);
	}
	dij(m);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}