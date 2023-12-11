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
ll a[maxn],b[maxn];
ll ma[maxn],mi[maxn];
int n,m;
ll k;
int f(int a,int b,int c)
{
	vector<int>now={a,b,c};
	sort(now.begin(),now.end());
	return now[1];
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	ma[n]=mi[m]=b[m];
	for(int i=m-1;i>=1;i--)
	{
		ma[i]=max(ma[i],b[i]);
		mi[i]=min(mi[i],b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(mi[i]<=a[i]&&ma[i]>=a[i])k=a[i];
		else if(k>=a[i]&&mi[1]>=k);
		else if(k<=a[i]&&ma[1]<=k);
		else 
	}
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
1 5 10
5
1 7 6 7 7
*/