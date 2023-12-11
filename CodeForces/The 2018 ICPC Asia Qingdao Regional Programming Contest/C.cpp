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
int p[maxn];
string s,t;
ll n;
void solve()
{
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
		if(s[i]==t[i])p[i]=0;
		else p[i]=1;
	// for(int i=0;i<n;i++)
	// 	cout<<p[i];
	// cout<<endl;
	vector<pii>v;
	v.push_back({p[0],1});
	for(int i=1;i<n;i++)
		if(p[i]!=p[i-1])
			v.push_back({p[i],1});
		else v.back().second++;

	int cnt=0,sum=0;
	for(auto [i,j]:v)
		if(i==1)cnt++;


	if(cnt>2){
		cout<<0<<endl;
		return ;
	}
	if(cnt==1&&n==1){
		cout<<0<<endl;
		return ;
	}


	if(cnt==0)cout<<(1ll*n*(n+1)/2)<<endl;
	else if(cnt==1)cout<<1ll*(n-1)*2<<endl;
	else cout<<6<<endl;



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
01010
00111

01101

11111
11101

l r a b
a b l r
l a b r
b r l a


111
1 1 2 3
2 3 1 1

1 2 3 3
3 3 1 2

1 1 2 2
2 2 1 1
*/