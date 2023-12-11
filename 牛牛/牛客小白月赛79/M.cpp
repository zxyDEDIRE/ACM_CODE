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
	void kmp(char *s,char *t)
	{
		int lens=strlen(s+1);
		int lent=strlen(t+1);
		int cnt=0;
		for(int i=0,j=0;i<lens;i++)
		{
			while(j&&s[i+1]!=t[j+1])j=nxt[j];
			if(s[i+1]==t[j+1])j++;
			if(j==lent)
			{
				cnt++;
				j=nxt[j];
			}
		}
	}
	/* 循环周期 形如 acaca 中 ac 是一个合法周期 */
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
	/* 循环节 形如 acac 中ac、acac是循环节，aca不是*/
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
	void debug(){
		for (int i=0;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}kmp;
class StringHash{
	public:
		ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
		ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
		ull seed[4]={911,146527,19260817,91815541};
		ull mod=212370440130137957ll;
		ull prime=233317;
		ull base=131;
		vector<ull>h;
		vector<ull>bas;
		StringHash():h(1),bas(1,1),base(131){}
		StringHash(int x,int y):h(1),bas(1,1){base=seed[x];mod=Mod_Pool[y];}
		void push_back(char ch){
			h.push_back((h.back()*base+ch)%mod + prime);
			bas.push_back(bas.back()*base%mod);
		}
		// ull get(int l,int r){
		// 	return (h[r] + __int128(h[l])*(mod-bas[r-l]))%mod;
		// }
		ull get(int l,int r){
			return (h[r]-h[l-1]*bas[r-l+1]%mod+mod)%mod;
		}
	};
char s[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	kmp.init(s);
	vector<int>v=kmp.periodic_loop();
	int t=v[0];
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;

	StringHash sh;
	for(int i=1;i<=n;i++)
		sh.push_back(s[i]);

	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int len=(r-l+1);
		if((r-l+1)%t==0 && l%t==0  &&n%len==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
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
abababab
abaabaabaaba

9 1
ababababa
0 8

6 1
ababab
2 5
*/