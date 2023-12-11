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
int a[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
		a[i]=p[i]-p[i+1];
	sort(a+1,a+n,[&](int a,int b){
		return a>b;
	});
	int ma=p[1]-p[n];
	for(int i=1;i<n;i++)
		a[i]+=a[i-1];
	int q;cin>>q;
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			cout<<ma-a[x-1]<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}