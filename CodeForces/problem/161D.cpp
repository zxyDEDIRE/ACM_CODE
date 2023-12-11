/*！*/
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
int del[maxn];
int siz[maxn];
int maxson,sum,root;
int n,m;
void getroot(int x,int fa)
{
	siz[x]=1;
	int mx=0;
	for(auto y:v[x])
	{
		if(y==fa||del[y])continue;
		getroot(y,x);
		siz[x]+=siz[y];
		mx=max(mx,siz[y]);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	maxson=sum=n;
	getroot(1,0);
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
f3f23facb05c8a33cb36d2bb95e17b089a5f2dbb
abe61a4fac4af497abf6d24f9c0bda6161231b8c
*/