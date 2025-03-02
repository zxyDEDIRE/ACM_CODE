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
const int N=1e3+10;
char mp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	pii s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]>='A'&&mp[i][j]<='Z'){
				s={i,j};
			}
		}
	int cnt=0;
	int dx,dy;
	auto [i,j]=s;
	if(mp[i][j]=='A')dx=0,dy=-1;
	if(mp[i][j]=='D')dx=0,dy=1;
	if(mp[i][j]=='W')dx=-1,dy=0;
	if(mp[i][j]=='S')dx=1,dy=0;
	while(1<=i&&i<=n&&1<=j&&j<=m)
	{
		if(mp[i][j]=='*')cnt++;
		i+=dx;
		j+=dy;
	}
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