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
const int N=1111;
char mp[N][N];
int n,m;
bool f(int x,int y)
{
	map<char ,int>q;
	q[mp[x][y]]=1;
	q[mp[x+1][y]]=1;
	q[mp[x][y+1]]=1;
	q[mp[x+1][y+1]]=1;
	if(!q.count('y')||!q.count('o')||!q.count('u'))return 0;
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
		int cnt=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(f(i,j))cnt++;
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}