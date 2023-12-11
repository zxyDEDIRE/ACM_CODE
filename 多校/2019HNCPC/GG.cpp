#pragma GCC optimize(2)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inff = 0x3f3f3f3f3f3f3f3f;
#define FOR(i,a,b) for(int i(a);i<=(b);++i)
#define FOL(i,a,b) for(int i(a);i>=(b);--i)
#define REW(a,b) memset(a,b,sizeof(a))
#define inf int(0x3f3f3f3f)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define mod ll(1000)
#define pb push_back
#define eps 1e-8
#define lc d<<1
#define rc d<<1|1
#define Pll pair<ll,ll>
#define P pair<int,int>
#define pi acos(-1)
const int N=2e3+8;
int a[N][N],n,m,ans[N];
bitset<2008>bt[N],st[N],ss;
bool cmp(P a,P b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
priority_queue<int,vector<int>,greater<int> >g;
vector<int>gg;
int main()
{
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>m)
	{
		while(!g.empty()) g.pop();
		gg.clear();
		FOR(i,1,n)
		 FOR(j,1,m) 
		 	si(a[i][j]);
		FOR(i,1,m) bt[i].reset(),st[i].reset();
		FOR(i,1,m)
		{
			int qw=1;
			bt[i][1]=st[i][1]=1;
			FOR(j,2,n)
			 if(a[j][i]>=a[j-1][i]) bt[i][j]=1;
			qw=bt[i].count();
			if(qw==n) g.push(i);
			else gg.pb(i);
			FOR(j,2,n)
			 if(a[j][i]>a[j-1][i]) st[i][j]=1;
		}
		int num=0;ss.reset();
		while(!g.empty())
		{
			int zz=g.top();g.pop();
			ans[++num]=zz;
			for(int i=0;i<gg.size();i++)
			{
				if(gg[i]==inf) continue;
				bt[gg[i]]|=st[zz];
				int qw=bt[gg[i]].count();
				if(qw==n) g.push(gg[i]),gg[i]=inf;
			}
		}
		if(num!=m) {puts("-1");continue;}
		FOR(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
