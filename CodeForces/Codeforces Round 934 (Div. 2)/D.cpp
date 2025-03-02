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
}Manch;
char s[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	Manch.init(s);
	Manch.manacher();
	// Manch.debug();

	vector<int>a,b;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i+1])a.push_back(i);
		if(i+2<=n&&s[i]!=s[i+2])b.push_back(i);
	}


	while(m--)
	{
		int l,r;
		cin>>l>>r;
		ll len=r-l+1;
		int fl;
		ll ans=0;

		if(l==r){
			cout<<0<<endl;
			continue;
		}
		fl=lower_bound(a.begin(),a.end(),l)-a.begin();

		if(fl==(int)a.size() || a[fl]>=r)
		{
			ans=0;
		}
		else
		{
			fl=lower_bound(b.begin(),b.end(),l)-b.begin();
			if(fl==(int)b.size() || b[fl]>=r-1) // sb 奇数
			{
				ll x=(len-1)/2;
				ans=(1+x)*x;
			}
			else
			{
				ans=len*(len-1)/2-1;
			}
		}
		if(Manch.lc[l+r]<len)ans+=len;
		cout<<ans<<endl;
	}

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
aaab
2 3 4

babab

aaaabaaaa
133191331

3 5 7
aabbaa
abababab
1 3
 123456
@#a#a#a#b#
lc[1]=1
lc[2]=2
lc[3]=3
lc[4]=4
lc[5]=3
lc[6]=2
lc[7]=1
lc[8]=2
lc[9]=1

1
5 1
pqpcc
1 3
2
*/