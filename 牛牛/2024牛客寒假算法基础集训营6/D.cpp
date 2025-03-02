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
string str,x;
void solve()
{
	cin>>x>>str;
	x=x.substr(2);
	int now=stol(x);
	now = now/2+1;
	int a=0,b=0;
	for(int i=0;i<(int)str.size();i++)
	{
		if(str[i]=='R')a++;
		else b++;
		if(a==now){
			cout<<"kou!\n"<<i+1;
			return ;
		}
		if(b==now){
			cout<<"yukari!\n"<<i+1;
			return ;
		}
	}
	cout<<"to be continued.\n"<<(int)str.size();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}