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
int p[maxn],a[maxn],b[maxn],c[maxn];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		m=max(m,p[i]);
		a[p[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j+=i)
			b[j]+=a[i],c[j]++;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		cnt+=(c[i]==b[i]);
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}