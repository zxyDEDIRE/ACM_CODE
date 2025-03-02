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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n,k,a;
int num;
string f(int x)
{
	string str;
	while(x){
		str.push_back('0'+x%2);
		x>>=1;
	}
	reverse(str.begin(),str.end());
	return str;
}
void solve()
{
	cin>>n>>k;
	a=INF;
	for(int i=1,x;i<=n;i++)
		cin>>x,a=min(a,x);
	cout<<f(a)<<endl;
	vector<pii>v;
	for(int i=1;i<=1e5;i++)
	{
		int x=(i^a);
		if(x<=k)v.push_back({i,x});
	}
	sort(v.begin(),v.end());
	for(auto [x,y]:v)
		cout<<x<<" "<<y<<" "<<(x^y)<<endl;
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
  8421
110110
 11000


1 24
54
*/