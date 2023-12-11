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
int ext[maxn];
int n,m;
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
char st[maxn];
void kmp(char *s,char *t)
{
	int lens=strlen(s+1);
	int lent=strlen(t+1);
	int cnt=0;
	int tot=0;
	ext[0]=0;
	for(int i=1;i<=lens;i++)
	{
		st[++tot]=s[i];
		ext[tot]=ext[tot-1];
		while(ext[tot]&&st[tot]!=t[ext[tot]+1])
			ext[tot]=nxt[ext[tot]];
		if(st[tot]==t[ext[tot]+1])
			ext[tot]++;
		if(ext[tot]==lent)
		{
			cnt++;
			tot-=lent;
		}
	}
	for(int i=1;i<=tot;i++)
		cout<<st[i];
	cout<<endl;
}
char s[maxn],t[maxn];
void solve()
{
	cin>>s+1>>t+1;
	init(t);
	kmp(s,t);
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
0 1 2 3 4 5 6 7 8 9 
0 0 0 0 0 0 0 1 2 1 2 3 0 0 0 0 0
0 1 2 3 4 5 6 7 7 7 7 7 7 13 14 15 16
  w h a t t h e m o m o o o  f  u  n 
*/