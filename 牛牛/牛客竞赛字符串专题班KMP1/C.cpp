#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
vector<int>s,t;
int n,m,k;
struct KMP{
	int nxt[maxn];
	int len;
	void init(const vector<int>&s)
	{
		nxt[1]=0;
		len=s.size()-1;
		for(int i=2;i<=len;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i])
				nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
		}
	}
	int kmp(const vector<int>&s,const vector<int>&t)
	{
		int lens=s.size()-1;
		int lent=t.size()-1;
		int cnt=0;
		for(int i=0,j=0;i<lens;i++)
		{
			while( j && (s[i+1]+t[j+1])%k!=0)j=nxt[j];
			if((s[i+1]+t[j+1])%k==0)j++;
			if(j==lent)
			{
				cnt++;
				j=nxt[j];
			}
		}
		return cnt;
	}
}kmp;
void solve()
{
	cin>>n>>m>>k;
	s.resize(n+1);
	t.resize(m+1);
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<n;i++)
		s[i]=((s[i+1]-s[i])%k+k)%k;
	for(int i=1;i<m;i++)
		t[i]=((t[i+1]-t[i])%k+k)%k;
	s.pop_back();
	t.pop_back();
	kmp.init(t);
	cout<<kmp.kmp(s,t)<<endl;
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
/*
6 3 3
1 2 3 1 2 3
1 2 3 

6 4 4
2 4 2 4 2 4
4 2 4 2 
  4 2 4 2
*/