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
vector<ll>check;
int f[maxn][100];
int n,m,q;
ll v;
int find(int x,int y){
	return f[x][y]=f[x][y]==x?f[x][y]:find(f[x][y],y);
}
void un(int x,int y,int t)
{
	int fa=find(x,t);
	int fb=find(y,t);
	if(fa!=fb)
		f[fa][t]=f[fb][t];
}
void solve()
{
	cin>>n>>m>>q>>v;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=100;j++)
			f[i][j]=i;
	ll val=0;
	for(int i=60;i>=0;i--)
	{
		if(v&(1ll<<i))
		{
			val|=(1ll<<i);
			if(val==v)
			{
				check.push_back(val);
				i=-1;
			}
		}
		else check.push_back(val|(1ll<<i));
	}
	int tot=check.size();
	for(int i=1;i<=m;i++)
	{
		int x,y;ll w;
		cin>>x>>y>>w;
		for(int j=0;j<check.size();j++)
		{
			ll s=check[j];
			if((w&s)==s)
				un(x,y,j);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int flag=0;
		for(int i=0;i<=tot;i++)
		{
			int fa=find(x,i);
			int fb=find(y,i);
			if(fa==fb)flag=1;
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}