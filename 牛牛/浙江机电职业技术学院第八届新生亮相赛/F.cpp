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
	string str,t;
	int n,m;
	cin>>n>>m>>str;
	while(m--)
	{
		string op;int l,r;
		cin>>op;
		if(op=="cc")
		{
			cin>>l>>r;
			t=str.substr(l-1,r-l+1);
		}
		else if(op=="cv")
		{
			cin>>l;
			if(l>str.size())continue;
			string now=str.substr(0,l) + t + str.substr(l,str.size()-l);
			str=now;
			// cout<<now<<endl;
		}
		else if(op=="cx")
		{
			cin>>l>>r;
			t=str.substr(l-1,r-l+1);
			string now=str.substr(0,l-1) + str.substr(r,str.size()-r+1);
			str=now;
			// cout<<t<<" "<<str<<endl;
		}
	}
	cout<<str<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}