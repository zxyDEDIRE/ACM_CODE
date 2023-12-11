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
const int maxn=1e5+100;
int p[maxn][62];
int n,m,q;
ll V;
int find(int r,int fl){
	return p[r][fl]=p[r][fl]=r?p[r][fl]:find(p[r][fl],fl);
}
void solve()
{
	cin>>n>>m>>q>>V;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=60;j++)
			p[i][j]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;ll w;
		cin>>x>>y>>w;
		for(int i=60;i>=0;i--)
		{
			ll t=(1ll<<i);
			if(w>=t)
			{
				w-=t;
				int fa=find(x,i);
				int fb=find(y,i);
				if(fa!=fb){
					p[fa][i]=p[fb][i];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		ll ans=0;
		cin>>x>>y;
		
	}
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