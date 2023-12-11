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
struct ExKmp{
//result: ext[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//nxt : s  Mode_String
//ext : s  Text_String t Mode_String
	
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
map<char,char>mp,pm;
int nxt[maxn],ext[maxn];
char s[maxn],t[maxn];
string str;
int n;
void solve()
{
	for(int i=0;i<26;i++){
		char c;cin>>c;
		mp[i+'a']=c;
		pm[c]=i+'a';
	}
	cin>>str;

	n=str.size();
	for(int i=1;i<=n;i++)
	{
		s[i]=str[i-1];
		t[i]=mp[s[i]];
	}
	s[n+1]=t[n+1]='\0';


	exkmp(s,strlen(s+1),s,strlen(s+1),nxt,nxt);
	exkmp(t,strlen(t+1),s,strlen(s+1),ext,nxt);
	int len=(strlen(s+1)+1)/2;
	for(;len<=strlen(s+1);len++)
	{
		int t=strlen(s+1)-len;
		// cout<<len<<" "<<t<<endl;
		if(ext[len+1]==t)break;
	}
	for(int i=1;i<=len;i++)
		cout<<s[i];
	for(int i=1;i<=len;i++)
		cout<<pm[s[i]];
	cout<<endl;
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

*/