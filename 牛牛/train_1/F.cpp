#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
using ull=unsigned long long;
using ll=long long;
const ull mod=212370440130137957ll;
const ull prime=233317;
const ull base=131;
const ull more=19260817;
vector<int>dic;
map<ull,int>mp;
bool vis[maxn];
bool ok[maxn];
ull a[maxn];
char s[maxn];
int n;
ull get_hash(char *s,int len)
{
	ull ans=0;
	for(int i=1;i<=len;i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}
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
	void periodic()
	{
		int now=len;
		while(now)
		{
			now=nxt[now];
			if(len%(len-now)==0)
				ok[len-now]=1;
		}
	}
}kmp;
struct Manacher{
	char ch[maxn];
	int lc[maxn];
	int N;
	void init(char *s){
		int n=strlen(s+1);
		// puts(s+1);
		ch[n*2+1]='#';
		ch[0]='@';
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]='#',vis[i]=ok[i]=0;
		N=n*2+1;
	}
	int manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
			if(i-(lc[i]-1)<=2)
			{
				if(i&1) vis[(i+(lc[i]-1))/2]=1;
				else vis[(i+(lc[i]-1))/2]=1;
			}
			if(i%2==0&&vis[i/2]==1&&ok[i/2]==1)
				return i/2;
		}
		return -1;
	}
}Manch;
void solve()
{
	cin>>n;
	ll ans=n;
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len>>s+1;
		Manch.init(s);
		kmp.init(s);
		kmp.periodic();
		int now=Manch.manacher();
		ull ha = get_hash(s,now);
		if(mp.count(ha))
			ans+=1ll*mp[ha]*2;
		mp[ha]++;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4
2 aa
2 aa
2 aa
2 aa
*/