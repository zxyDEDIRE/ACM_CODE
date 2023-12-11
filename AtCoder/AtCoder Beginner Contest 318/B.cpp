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
int s[111][111];
int p[111][111];
int n;
void insert(int x1,int y1,int x2,int y2,int c)
{
	s[x1][y1]+=c;
	s[x2+1][y2+1]+=c;
	s[x1][y2+1]-=c;
	s[x2+1][y1]-=c;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>x2>>y1>>y2;
		x1++;y1++;
		insert(x1,y1,x2,y2,1);
	}
	int cnt=0;
	for(int i=1;i<=101;i++)
	{
		for(int j=1;j<=101;j++){
			p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+s[i][j];
		}
	}
	for(int i=0;i<=101;i++)
		for(int j=0;j<=101;j++)
			if(p[i][j])cnt++;
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}