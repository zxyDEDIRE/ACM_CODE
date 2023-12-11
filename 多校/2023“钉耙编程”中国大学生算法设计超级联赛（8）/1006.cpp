// #pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e7+100;
struct ExKmp{
//result: ext[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//nxt : s  Mode_String
//ext : s  Text_String t Mode_String
	void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
	{
		ext[0]=0;
		for(int i=1,p0=0,p=0;i<=lens;i++)
		{
			ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
			while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
			if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
		}
	}
	void debug_ext(int *ext,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] ext[%d]=%d\n",i,ext[i]);
		}
	}
	void debug_nxt(int *nxt,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}exKMP;
char rs[maxn];
char rt[maxn];
char t1[maxn];
char t2[maxn];
char s[maxn];
int nxt_t1[maxn];
int nxt_t2[maxn];
int nxt_s[maxn];
int nxt_rt[maxn];
int nxt_rs[maxn];
int nxt[maxn];
int sum[maxn];
int len_t1,len_t2,len_s,tot;
long long ans;
void solve()
{
	scanf("%s%s%s",t1+1,t2+1,s+1);
	len_t1=strlen(t1+1);
	len_t2=strlen(t2+1);
	len_s=strlen(s+1);
	tot=len_t1+len_t2;ans=0;
	for(int i=1;i<=len_t1;i++)rt[len_t1-i+1]=t1[i];
	for(int i=1;i<=len_s;i++)rs[len_s-i+1]=s[i],sum[i]=0;
	exKMP.exkmp(t1,len_t1,t1,len_t1,nxt_t1,nxt_t1);
	exKMP.exkmp(s ,len_s ,t1,len_t1,nxt_s ,nxt_t1);
	exKMP.exkmp(rt,len_t1,rt,len_t1,nxt_rt,nxt_rt);
	exKMP.exkmp(rs,len_s ,rt,len_t1,nxt_rs,nxt_rt);
	exKMP.exkmp(t2,len_t2,t2,len_t2,nxt_t2,nxt_t2);
	exKMP.exkmp(s ,len_s ,t2,len_t2,nxt   ,nxt_t2);

	for(int i=1;i<=len_s;i++)
	{
		if(nxt[i]==len_t2)
			sum[i+len_t2-1]++;
		sum[i]+=sum[i-1];
	}

	// for(int i=1;i<=len_s;i++)
	// 	cout<<sum[i]<<" ";cout<<endl;

	// for(int i=1;i<=len_s;i++)
	// 	cout<<nxt_s[i]<<" ";cout<<endl;

	// for(int i=1;i<=len_s;i++)
	// 	cout<<nxt_rs[i]<<" ";cout<<endl;

	// for(int i=1;i<=len_s;i++)
	// 	cout<<rs[i]<<" ";cout<<endl;

	for(int i=1;i+tot-1<=len_s;i++)
	{
		int r=i+nxt_s[i]-1+len_t2;
		int l=i+tot-1 - nxt_rs[len_s-(i+tot-1)+1];
		// cout<<i<<" "<<l<<" "<<r<<" "<<sum[r]-sum[l-1]<<endl;
		if(r>=l)ans+=sum[r]-sum[l-1];
	}
	cout<<ans<<endl;
	printf("%lld\n",ans);

}
signed main(){
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}