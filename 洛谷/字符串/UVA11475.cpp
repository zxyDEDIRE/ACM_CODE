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
int nxt[maxn];
int p[maxn];
string s,t;
int n;
void init()
{
	nxt[1]=0;
	for(int i=2;i<=n;i++)
	{
		nxt[i]=nxt[i-1];
		while(t[nxt[i]+1]!=t[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(t[nxt[i]+1]==t[i])nxt[i]++;
	}
}
void kmp()
{
	int lens=n;
	int lent=n;
	int cnt=0;
	int ans=0;
	for(int i=0,j=0;i<lens;i++)
	{
		while(j&&s[i+1]!=t[j+1])j=nxt[j];
		if(s[i+1]==t[j+1])j++;
		ans=j;
		if(j==lent)
		{
			cnt++;
			j=nxt[j];
		}		
	}
	// cout<<ans<<endl;
	for(int i=1;i<=n;i++)cout<<s[i];
	for(int i=ans+1;i<=n;i++)
		cout<<t[i];
	cout<<endl;
}
void solve()
{
	t=s;
	n=s.size();
	reverse(t.begin(),t.end());
	s=" "+s;
	t=" "+t;
	init();
	kmp();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>s)
		solve();
	return 0;
}
