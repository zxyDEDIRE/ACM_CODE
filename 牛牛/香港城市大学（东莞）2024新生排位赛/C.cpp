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
void solve()
{
	ll n;
	cin>>n;
	if(n<10)
	{
		if(n%3)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	else
	{
		if(n%2)cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
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
/*
1 a
2 a
3 b
4 a
5 a
6 b
7 a
8 a
9 b
10 a
11 b
12 a
13 b
14 a
15 b
16 a
17 b





*/