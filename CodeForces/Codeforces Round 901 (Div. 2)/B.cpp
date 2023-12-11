#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int b[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1,a+1+n,[&](int a,int b){return a>b;});
	sort(b+1,b+1+m,[&](int a,int b){return a>b;});
	if(a[n]<b[1])swap(a[n],b[1]);
	sort(a+1,a+1+n,[&](int a,int b){return a>b;});
	sort(b+1,b+1+m,[&](int a,int b){return a>b;});
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(k&1)cout<<sum<<endl;
	else cout<<sum-a[1]+b[m]<<endl;
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
1 1 1
2
1
*/