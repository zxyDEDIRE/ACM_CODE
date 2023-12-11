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
const int N=1011;
vector<pii>p[N];
int mp[N][N];
int s[N][N];
int m,n,k;
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
		}
}
int get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve()
{
	cin>>m>>k>>n;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=x;j<=x+k-1;j++)
			p[j].push_back({y,y+k-1});
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].size()==0)continue;
		sort(p[i].begin(),p[i].end());
		int r=-1,len=p[i].size();
		for(int j=0;j<len;j++)
		{
			auto [_l,_r]=p[i][j];
			if(_l<=r)
			{
				while(r<_r){
					r++;
					mp[i][r]=1;
				}
				r=max(r,_r);
			}
			else
			{
				r=_l;mp[i][r]=1;
				while(r<_r){
					r++;
					mp[i][r]=1;
				}
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 		cout<<mp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	init();
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<k*k-get(x,y,x+k-1,y+k-1)<<endl;
	}
	// cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
2 1 3

*/