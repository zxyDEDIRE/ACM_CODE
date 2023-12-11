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
char s[maxn];
int nxt[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	exkmp(s,n,s,n,nxt,nxt);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=nxt[i];
	cout<<ans%10007<<endl;
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