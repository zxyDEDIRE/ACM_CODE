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
const int N=111;
int mp[N][N];
int n,m,x;
void NO(){cout<<"wrong answer"<<endl;}
void solve()
{
	cin>>n>>m>>x;
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j],sum+=mp[i][j];
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=1;j<=m;j++)
			now=(now^mp[i][j]);
		s.insert(now);
	}
	for(int i=1;i<=m;i++)
	{
		int now=0;
		for(int j=1;j<=n;j++)
			now=(now^mp[j][i]);
		s.insert(now);
	}
	if(sum!=x || s.size()!=1)return NO();
	cout<<"accepted"<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}