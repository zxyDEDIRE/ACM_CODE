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
	void query(int n);
}Manch;
StringHash h;
int nxt[maxn];
char ch[maxn];
string str;
int n;

void YES(){cout<<"Yes\n";}

void Manacher::query(int n)
{
	for(int i=1;i<=N;i++)
	{
		if(i==lc[i])
		{
			int l=(i+lc[i])/2;
			int r=N/2;
			if((r-l+1)%2==0)
			{
				int mid=(l+r)>>1;
				// cout<<"A-";
				if(h.get(l,mid)==h.get(mid+1,r))return YES();
				// cout<<"A"<<endl;
			}
		}
		if(i+lc[i]-1==N)
		{
			int l=1;
			int r=(i-lc[i])/2;
			if((r-l+1)%2==0)
			{
				int mid=(l+r)>>1;
				// cout<<l<<" "<<mid<<" "<<h.get(l,mid)<<endl;
				// cout<<mid+1<<" "<<r<<" "<<h.get(mid+1,r)<<endl;
				// cout<<"B-";
				if(h.get(l,mid)==h.get(mid+1,r))return YES();
				// cout<<"B"<<endl;
			}
		}
	}
	int mid=(1+N)>>1;
	int l=(mid-lc[mid])/2;
	int r=(mid+lc[mid])/2;
	if(h.get(1,l)==h.get(r,n))return YES();
	cout<<"No\n";
}
void solve()
{
	cin>>str;
	h = StringHash(1,2);
	n=str.size();
	int l=0,r=n-1;
	while(l<r && str[l]==str[r])
		l++,r--;
	n=0;
	
	for(int i=l;i<=r;i++)
	{
		ch[++n]=str[i];
		h.push_back(str[i]);
	}
	ch[n+1]='\0';

	Manch.init(ch);
	Manch.manacher();
	Manch.query(n);

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

aabccdbaa
aba dc dc

ddc aba ddc
ddcabaddc

dc dc aba
dcdc aba

asdasdcccc



2
bacad
ddcabaddc
*/