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
const int N=100;
int mp[N][N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
				v.push_back(mp[i][j]);
		}
		else
		{
			for(int j=n;j>=1;j--)
				v.push_back(mp[i][j]);
		}
	}
	int cnt=0;
	for(int i=1;i<v.size();i++)
		if(v[i-1]>v[i])cnt++;
	int len=v.size();
	if(cnt+cnt<len)
	{
		reverse(v.begin(),v.end());
	}
	for(auto i:v)
		cout<<i<<" ";cout<<endl;
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
1
2
1 2 
4 3
*/