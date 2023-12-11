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
const int maxn=6e3+100;
vector<int>v[maxn];
int dep1[maxn];
int dep2[maxn];
int p1[maxn];
int p2[maxn];
int tt[maxn];
int n,m;
void dfs1(int x,int fa)
{
	dep1[x]=dep1[fa]+1;
	p1[x]=fa;
	for(auto y:v[x])
		if(y!=fa)
			dfs1(y,x);
}
void dfs2(int x,int fa)
{
	dep2[x]=dep2[fa]+1;
	p2[x]=fa;
	for(auto y:v[x])
		if(y!=fa)
			dfs2(y,x);
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	long long x1,y1,d;
	d=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return d;
}
long long get(int s,int t,int s1,int t1)
{
	long long x,y,d;
	d=exgcd(tt[0],tt[1],x,y);
	if((dep1[t]-dep2[t1])%d) return 1e18;
	x*=(dep1[t]-dep2[t1])/d,y*=(dep1[t]-dep2[t1])/d;
	long long a1=tt[0]/d,b1=tt[1]/d,k1,k2;
	k1=(-x)/b1,k2=y/a1;
	if((-x)<0&&(-x)%b1) k1--;
	if(y<0&&y%a1) k2--;
	if(k1>k2) return 1e18;
	return max(dep2[t1]+(y-a1*k1)*tt[1],dep2[t1]+(y-a1*k2)*tt[1]);
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep1[0]=dep2[0]=-1;
	while(m--)
	{
		int s1,s2,t1,t2;
		scanf("%d%d",&s1,&t1);
		scanf("%d%d",&s2,&t2);
		dfs1(s1,0);
		dfs2(s2,0);
		map<int,int>mp;
		int x=t1;
		int le1=0,le2=0;
		dep1[t1+n]=dep1[t1];
		do{
			if(x==t1)
			dep1[p1[x]+n]=dep1[x]+1;
			else
			dep1[p1[x]+n]=dep1[x+n]+1;
			mp[x]++;
			x=p1[x];
		}while(x!=s1);
		tt[0]=dep1[s1+n];
		mp[x]=1;
		x=t2;
		vector<int>v;
		dep2[t1+n]=dep2[t1];
		do{
			if(x==t2)
			dep2[p2[x]+n]=dep2[x]+1;
			else
			dep2[p2[x]+n]=dep2[x+n]+1;
			if(mp.count(x))
			{
				v.push_back(x);
			}
			x=p2[x];
			le2=dep2[x+n];
		}while(x!=s2);
		tt[1]=dep2[s2+n];
		if(mp.count(x))
		{
			v.push_back(x);
		}
		if(v.size()==0)
		{
			puts("-1");continue;
		}
		long long ans=1e18;
		int op=-1;
		for(int j=0;j<(int)v.size();j++)
		{
			int u=v[j];
			long long t1=get(s1,u,s2,u),t2=get(s1,u+n,s2,u),t3=get(s1,u,s2,u+n),t4=get(s1,n+u,s2,n+u);
			if(ans>min(min(t1,t2),min(t3,t4)))
			{
				op=u;
				ans=min(min(t1,t2),min(t3,t4));
			}
		}
		printf("%d\n",op);
	}

}
signed main(){
	 int __;
	 scanf("%d",&__);
	 while(__--)
		solve();
	return 0;
}
