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
const int maxn=1e6+100;
char s[maxn];
ll INF[maxn];
ll F[maxn];
string str;
int n;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void init()
{
	F[0]=1;
	F[1]=1;
	for(int i=2;i<=2e5;i++)
	{
		F[i]=(F[i-1]*i)%mod;
		INF[i]=ksm(F[i],mod-2);
	}
}
int A(int n,int m)
{
	// if(m==0)return 1;
	return 1ll*F[n]*ksm(F[n-m],mod-2)%mod;
}
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
		s[i]=str[i-1];
	ll ans_1=0,ans_2=1;
	int cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])cnt++;
		else
		{
			ans_1+=cnt-1;
			ans_2*=cnt;
			ans_2%=mod;
			cnt=1;
		}
	}
	ans_1+=cnt-1;
	ans_2*=cnt;ans_2%=mod;
	ans_2*=F[ans_1];ans_2%=mod;
	cout<<ans_1<<" "<<ans_2<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
