#include<bits/stdc++.h>
using namespace std;
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}
ll getRand(ll l,ll r,ll fl){
	ll now=getRand(l,r);
	while(now==fl)now=getRand(l,r);
	return now;
}
ll getRand(ll l,ll r,set<int>&s){
	ll now=getRand(l,r);
	while(s.count(now))
		now=getRand(l,r);
	return now;
}
vector<pp(3)>v[maxn];
string T="ccsuCCSU";
signed main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// 32~126
	int n=atoi(argv[1]);
	for(int i=1;i<=n;i++)
	{
		char str=(char)getRand('a','z');
		int now=getRand(0,25);
		if(now<=10)
			str=(char)T[getRand(0,7)];
		else if(now<=15)
			str=(char)getRand('A','Z');
		else if(now<=20)
			str=(char)getRand('0','9');
		cout<<str;
	}




	return 0;
}