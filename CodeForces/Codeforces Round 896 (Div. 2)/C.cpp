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
int n,m;
void solve()
{
	cin>>n>>m;
	vector<vector<int>>p(n+1,vector<int>(m+1,0));
	vector<int>ma(n+1,0);
	p[1][1]=m-1;
	for(int j=2;j<=m;j++)
	{
		p[1][j]=j-2;
		for(int i=2;i<=min(n,j-1);i++)
			p[i][j]=p[i-1][j]-1,ma[i]=max(ma[i],p[i][j]);
	} 
	for(int i=2;i<=min(m-1,n);i++)
	{
		int t=m-i; 
		int x=t+2;
		int y=i+1;
		for(int j=x;j<y;j++)
			p[i][j]=j-2,ma[i]=max(ma[i],p[i][j]);
	}
	for(int i=2;i<=min(m-1,n);i++)
	{
		int x=ma[i]+1;
		for(int j=1;x<m;j++,x++)
			p[i][j]=x;
	}
	if(m==1)cout<<0<<endl;
	else cout<<min(n+1,m)<<endl;
	for(int i=1;i<=n;i++){
		int t=i;if(i>=m)t=1;
		for(int j=1;j<=m;j++)
			cout<<p[t][j]<<" \n"[j==m];
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

4 0 1 2 3
3 4 0 1 2
2 3 4 0 1
3 4 1 2 0

5 0 1 2 3 4
4 5 0 1 2 3
3 4 5 0 1 2
3 4 5 2 0 1
4 5 1 2 3 0
*/