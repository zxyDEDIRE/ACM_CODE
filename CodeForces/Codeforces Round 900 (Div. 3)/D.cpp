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
const int maxn=2e5+100;
char s[maxn];
int l[maxn];
int r[maxn];
int a[maxn];
int n,k;
void solve()
{
	cin>>n>>k;

	for(int i=1;i<=n;i++)
		cin>>s[i],a[i]=0;
	for(int i=1;i<=k;i++)
		cin>>l[i];
	for(int i=1;i<=k;i++)
		cin>>r[i];
	int q;cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		int fl=lower_bound(r+1,r+1+k,x)-r;
		int _l=l[fl];
		int _r=r[fl];
		int L=min(x,_l+_r-x);
		int R=max(x,_l+_r-x);
		a[L]++;
		a[R]++;
	}
	for(int i=1;i<=k;i++)
	{
		int L=l[i];
		int R=r[i];
		int cnt=0;
		while(L<R)
		{
			cnt+=a[L];
			if(cnt&1)swap(s[L],s[R]);

			L++,R--;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<s[i];
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