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
string str;
void solve()
{
	cin>>str;
	int n=str.size();
	str=" "+str;
	stack<int>s;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(')s.push(i);
		else if(s.size())
		{
			int l=s.top();s.pop();
			int r=n-i+1;
			ans+=2ll*l*r;
		}
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}