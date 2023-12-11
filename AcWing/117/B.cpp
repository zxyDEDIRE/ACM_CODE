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
int n;
int f(char ch){
	if(ch>='a'&&ch<='z')return ch-'a';
	else return ch-'A'+26;
}
void solve()
{
	cin>>n>>str;
	int ans=0;
	vector<int>v(100,0);
	for(auto i:str)
	{
		int x=f(i);
		if(x<26)v[x]++;
		else if(v[x-26])v[x-26]--;
		else ans++;
	}
	cout<<ans<<endl;
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