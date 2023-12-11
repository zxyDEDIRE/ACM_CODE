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
class Hash{
	public:
		ull Prime_Pool[3] = {233317ull,1998585857ul,23333333333ul};
		ull Seed_Pool[4]={911,146527,19260817,91815541};
		ull Mod_Pool[5]={29123,998244353,1000000009,4294967291ull,212370440130137957ll};
		ull sum[maxn],bas[maxn];
		int perm[maxn];
		int sigma;
		ull Seed,Mod;
		int N;
		Hash(int x,int y):Seed(Seed_Pool[x]),Mod(Mod_Pool[y]){
		}
		void init(string&s){
			N=s.size();
			for(int i=1;i<=N;i++)
				sum[i]=(sum[i-1]*Seed%Mod+s[i-1])%Mod;
			bas[0]=1;
			for(int i=1;i<=N;i++)
				bas[i]=bas[i-1]*Seed%Mod;
		}
		ull get(int l,int r){
			return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
		}
}h[2]{Hash(2,4),Hash(3,3)};
// 2 2 18
// 2 3 36
// 2 4 9
// 3 3 37
// 3 4 9


void exkmp(string&s,int lens,string&t,int lent,int *ext,int *nxt)
{
	ext[0]=0;
	for(int i=1,p0=0,p=0;i<=lens;i++)
	{
		ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
		while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]-1]==t[ext[i]+1-1])ext[i]++;
		if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
	}
}


char ch[maxn];
int nxt[maxn];
string p[maxn];
ll ans=0;
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,[&](string&a,string&b){
		if(a.size()!=b.size())return a.size()<b.size();
		return a<b;
	});
	map<ull,int>mp;
	for(int i=1;i<=n;i++)
	{
		string&str=p[i];
		int len=str.size();
		h[0].init(str);

		// cout<<"I:"<<i<<endl;
		// cout<<str<<endl;
		// cout<<"H "<<h[0].get(1,len)<<endl;

		exkmp(str,len,str,len,nxt,nxt);
		int L=-1;
		for(int i=len;i>1;i--)
			if(i+nxt[i]-1==len){
				L=nxt[i];
				if(L+1<=len-L)
				{
					ull now=h[0].get(L+1,len-L);
					if(mp.count(now))ans+=mp[now];
				}
			}
		ull now=h[0].get(1,len);
		if(mp.count(now))ans+=mp[now];
		mp[now]++;
	}
	cout<<ans<<endl;
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
cabc
1  1
aaaaaa

6
a
aa
aaa
aaaa
aaaaa
aaaaaa

a 0
aa 0
aaa a 1
aaaa aa 1
aaaaa a aaa 2
aaaaaa aa aaaa 2

2
aafadf
caafadfc
*/