#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using PLL=pair<ull,ull>;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
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

class DoubleHash{
	public:
		const ull b1=137,b2=149,i1=1'603'801'661,i2=1'024'053'074;
		const ull p1=2'034'452'107, p2=2'013'074'419;
		ull m1[maxn],m2[maxn],r1,r2;
		PLL h[maxn];
		int N;
		void init(char*s){
			h[0]={0,0};
			int n=strlen(s+1);
			m1[0]=m2[0]=1;
			N=n+10;
			for(int i=1;i<=N;i++)
			{
				m1[i]=m1[i-1]*b1%p1;
				m2[i]=m2[i-1]*b2%p2;
			}
			h[0]={0,0};
			for(int i=1;i<=n;i++)
			{
				r1=(r1+s[i]*m1[i])%p1;
				r2=(r2+s[i]*m2[i])%p2;
				h[i]={r1,r2};
			}
		}
		PLL getv(int l,int r){
			return {(p1+h[r].first-h[l].first)*m1[N-l]%p1,(p2+h[r].second-h[l].second)*m2[N-l]%p2};
		}
		ull get(int l,int r){
			PLL a=getv(l,r);
			return (ull)a.first<<32|a.second;
		}
	}h;
char s[maxn];
int n;
void solve()
{
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>s[i];
	h.init(s);
	Manch.init(s);
	Manch.manacher();
	map<PLL,bool>mp;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int len;

		len=Manch.lc[i*2]/2;
		// cout<<"I:"<<i<<endl;
		while(len>1)
		{
			int l=i-(len)+1;
			int r=i+(len)-1;
			// ull now=H.get(l,r);
			PLL now = h.getv(l,r);
			// cout<<"len "<<len<<" "<<l<<" "<<r<<endl;
			if(mp.count(now)){
				ans=max(ans,len);
				break;
			}
			else{
				mp[now]=1;
				len--;
			}
		}
	}
	cout<<ans<<endl;
	// cout<<H.get(1,5)<<" "<<H.get(5,9)<<endl;
}
signed main(){
	//自定义开栈
	// int size(512<<20); // 512M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	// exit(0);
	return 0;
}
/*
123456789
abbbabbba

dabbbaccdabbba


*/