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
char s[maxn],t[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=m;i++)
		cin>>t[i];
	int fa=1,fb=1;

	for(int i=1;i<=n;i++)
	{
		if(s[i]!=t[i])fa=0;
		if(s[i]!=t[m-n+i])fb=0;
	}
	if(fa&&fb)cout<<0;
	else if(fa)cout<<1;
	else if(fb)cout<<2;
	else cout<<3;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1234
123
*/