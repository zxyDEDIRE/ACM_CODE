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
	string str;
	int cnt=0;
	while(cin>>str)
	{
		// cout<<str.substr(14)<<endl;
		string now=str.substr(15);
		// string res;
		// for(auto i:now)
		// 	if(i=='1')res=res+"r";
		// 	else res=res+"b";
		// now=res;
		// reverse(now.begin(),now.end());
		// while(now.back()=='0')now.pop_back();
		// reverse(now.begin(),now.end());

		cout<<"p["<<cnt<<"]=\""<<now<<"\";";
		cnt++;
	}
}
signed main(){
 freopen("d.in","r",stdin);
 freopen("e.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}