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
map<string,bool>mp;
int a[11];
int b[11];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		for(int j=0;j<5;j++)
		{
			cin>>str;
			mp[str]=1;
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		int x;
		cin>>str>>x;
		if(mp.count(str))a[x]++;
		else b[x]++;
	}
	int ans=INF;
	int sum=0;
	for(int i=1;i<=5;i++){
		// cout<<a[i]<<" ";cout<<endl;
		sum+=a[i];
	}
	ans=min(ans,sum);
	for(int i=1;i<=5;i++)
	{
		// cout<<b[i]+a[i]<<" ";cout<<endl;
		ans=min(ans,b[i]+a[i]);
	}
	cout<<ans<<endl;
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

*/