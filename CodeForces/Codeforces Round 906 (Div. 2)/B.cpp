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
string s,t;
int n,m;
int f(string &str)
{
	for(int i=0;i+1<str.size();i++)
		if(str[i]==str[i+1])return 0;
	return 1;
}
void solve()
{
	cin>>n>>m>>s>>t;
	int fa=f(s);
	int fb=f(t);
	if(!fa&&!fb){
		cout<<"No\n";
		return ;
	}
	if(fa){
		cout<<"Yes\n";
		return ;
	}
	char a=t[0];
	char b=t.back();
	for(int i=0;i+1<s.size();i++)
	{
		if(s[i]==s[i+1])
		{
			if(s[i]!=a&&b!=s[i+1]);
			else{
				cout<<"No\n";
				return ;
			}
		}
	}
	cout<<"Yes\n";
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