#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
char ch[maxn];
string str;
int n;
struct KMP{
	int nxt[maxn];
	int len;
	void init(char *s)
	{
		nxt[1]=0;
		len=strlen(s+1);
		for(int i=2;i<=len;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i])
				nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
		}
	}
	vector<int> periodic()
	{
		vector<int>ret;
		int now=len;
		while(now)
		{
			now=nxt[now];
			ret.push_back(len-now);
		}
		return ret;
	}
	vector<int> periodic_loop()
	{
		vector<int>ret;
		for(auto i:periodic())
		{
			if(len%i==0)
				ret.push_back(i);
		}
		return ret;
	}
}kmp;
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
		ch[i]=str[i-1];
	kmp.init(ch);
	auto x=kmp.periodic();
	int len=x[0];
	int y=x.back();
	// for(auto i:x)
	// 	cout<<i<<" ";cout<<endl;

	if(len!=n&&y%len==0)cout<<0<<endl;
	else if(len==n)cout<<n<<endl;
	else cout<<(len-y%len)<<endl; 
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