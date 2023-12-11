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
			ch[i*2]=s[i],ch[i*2-1]='#';
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
		// printf("%d\n",ma);
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
	bool check(int l,int r){
		int mid=(l*2+r*2)/2;
		if(r*2-mid+1>lc[mid])return 0;
		return 1;
	}
}Manch;
int pre[maxn];
char s[maxn];
int p[maxn];
string str;
int n;
void solve()
{
	for(int i=0;i<26;i++)
		cin>>p[i];
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++){
		s[i]=str[i-1];
		pre[i]=pre[i-1]+p[s[i]-'a'];
	}
	s[n+1]='\0';
	Manch.init(s);
	Manch.manacher();
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		int now=0;
		if(Manch.check(1,i-1))now+=pre[i-1];
		if(Manch.check(i,n))now+=pre[n]-pre[i-1];
		ans=max(ans,now);
	}
	cout<<ans<<endl;
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