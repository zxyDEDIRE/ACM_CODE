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
int sa[maxn],sb[maxn];
int a[maxn],b[maxn];
char s[maxn];
int n;
void solve()
{
	cin>>s+1;
	n=strlen(s+1);
	int fa=0,fb=1;
	for(int i=1;i<=n;i++)
	{
		fa^=1;fb^=1;
		if((s[i]&1)==fa)a[i]=1;
		if((s[i]&1)==fb)b[i]=1;
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+b[i];
	}
	int ans=0;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			ans+=min(sa[r]-sa[l-1],sb[r]-sb[l-1]);
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
*/