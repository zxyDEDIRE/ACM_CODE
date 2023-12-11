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
const int N=555;
char mp[N][N];
int cnt[N][2];
int n,m;
void solve()
{
	cin>>n>>m;
	memset(cnt,0,sizeof cnt);
	vector<vector<int>>a(m+1),b(n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]!='.')cnt[i][0]++,cnt[j][1]++;

			if(mp[i][j]=='L')a[j].push_back(i);
			if(mp[i][j]=='U')b[i].push_back(j);
		}
	for(int i=1;i<=max(n,m);i++)
		if((cnt[i][0]&1)||(cnt[i][1]&1)){
			cout<<"-1\n";
			return ;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<b[i].size();j+=2)
		{
			int x=b[i][j];
			int y=b[i][j+1];
			mp[i][x]=mp[i+1][y]='W';
			mp[i+1][x]=mp[i][y]='B';
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j+=2)
		{
			int x=a[i][j];
			int y=a[i][j+1];
			mp[x][i]=mp[y][i+1]='W';
			mp[x][i+1]=mp[y][i]='B';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<mp[i][j];
		cout<<endl;
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