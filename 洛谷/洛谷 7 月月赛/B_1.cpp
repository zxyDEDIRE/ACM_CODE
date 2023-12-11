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
map<pii,bool>mp;
int p[maxn];
int a[maxn];
int n,m;
int tot=0;
int A()
{
	int cnt=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=x+1;y<=n;y++)
		{
			// if(mp[{min(x,y),max(x,y)}]==1)continue;
			int now=1;if(x==1)now++;
			for(int i=1;i<=n;i++)
			{
				if(i==y)continue;
				a[i]=now;
				now++;
				if(now==x)now++;
			}
			a[y]=x;
			int flag=1;
			for(int i=1;i<=n;i++)
				if(p[i]&&p[i]!=a[i])
					flag=0;
			cnt+=flag;
		}
	}
	return cnt;
}
int B()
{
	int cnt=0;
	for(int x=2;x<=n;x++)
	{
		for(int y=1;y<x-1;y++)
		{
			// if(mp[{min(x,y),max(x,y)}]==1)continue;
			int now=1;
			for(int i=1;i<=n;i++)
			{
				if(i==y)continue;
				a[i]=now;
				now++;
				if(now==x)now++;
			}
			a[y]=x;
			int flag=1;
			for(int i=1;i<=n;i++)
				if(p[i]&&p[i]!=a[i])
					flag=0;
			cnt+=flag;
		}
	}

	return cnt;
}
void solve()
{
	cin>>n>>m;
	memset(p,0,sizeof(int)*(n+1));
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		p[x]=y;
	}
	for(int i=1;i<=n;i++)
		if(p[i])a[i]=p[i]-i;
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";cout<<endl;
	int ans=0;
	ans+=A();
	ans+=B();
	cout<<ans<<endl;
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
/*

1
40 21
1 1 2 2 6 6 7 7 8 8 9 9 10 10 11 11 15 15 16 16 23 23 24 24 25 25 26 26 30 30 34 35 35 36 36 37 37 38 38 39 40 40

1
40 15
3 3 4 4 14 14 15 15 17 17 19 19 24 23 25 24 27 26 30 29 31 30 33 32 35 34 39 38 40 39



1
4 2
1 1
2 4

1 4 0 0

1
4 0
*/