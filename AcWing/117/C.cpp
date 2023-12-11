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
map<string,int>mp;
int n,cnt=0;
int ma=0;
void dfs(int x,int dis)
{
	ma=max(ma,dis);
	for(auto y:v[x])
		dfs(y,dis+1);
}
void solve()
{
	cin>>n;
	cnt=1;
	mp["bessie"]=1;
	// cout<<(int)('A')<<" "<<(int)('a')<<endl;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		for(auto &i:a)
			if(i>='A'&&i<='Z')i+=32;
		for(auto &i:b)
			if(i>='A'&&i<='Z')i+=32;
		if(!mp.count(a))mp[a]=++cnt;
		if(!mp.count(b))mp[b]=++cnt;
		v[mp[b]].push_back(mp[a]);
	}
	dfs(1,1);
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}