#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
set<map<pii,int>>s;
int cnt=0;
void dfs(int x,map<pii,int>mp)
{
	if(s.count(mp))return ;
	s.insert(mp);
	// for(auto [_x,y]:mp)
	// 	cout<<_x.first<<" "<<_x.second<<endl;
	// cout<<endl;
	cnt++;
	for(int i=1;i<=7;i++)
	{
		for(int j=i;j<=7;j++)
		{
			if(abs(i-j)<=1)continue;
			if(mp.count({i,j}))continue;
			map<pii,int>now=mp;
			now[{i,j}]=1;
			dfs(x+1,now);
		}
	}
}
void solve()
{
	// dfs(0,{});
	// cout<<cnt<<e/ndl;
	cout<<log2(64)<<endl;
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
/*
7 32768 15
6 1024 10
5 64 6
4 8 3

*/