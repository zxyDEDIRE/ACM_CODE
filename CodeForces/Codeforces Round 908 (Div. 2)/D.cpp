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
vector<int>v[maxn];
pii p[maxn];
int a[maxn];
int b[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v[i].clear();
		p[i]={a[i],i};
	}
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(p+1,p+1+n,[&](pii a,pii b){
		if(a.first!=b.first)return a.first<b.first;
		return a.second>b.second;
	});
	vector<int>_c;
	sort(b+1,b+1+m,[&](int a,int b){
		return a>b;
	});
	for(int i=1;i<=m;i++)
	{
		int fl=lower_bound(p+1,p+1+n,pii{b[i],0})-p;
		if(fl>n)_c.push_back(b[i]);
		else v[p[fl].second].push_back(b[i]);
	}
	for(auto i:_c)cout<<i<<" ";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
		for(auto x:v[i])
			cout<<x<<" ";
	}
	cout<<endl;
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
1 3 5
2 4


4 2
1 3 2 5 4

1 5 3 8
1 2 3 4 5

1 1 5 5 4 3 3 2 8
*/