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
int n;
void solve()
{
	cin>>n;n*=2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	vector<int>x,y;
	for(int i=1;i<=n;i++)
	{
		if(i<=n/2)x.push_back(a[i]);
		else y.push_back(a[i]);
	}
	int ans=x.back()-x[0]+y.back()-y[0];
	cout<<ans<<endl;
	for(int i=0;i<(n/2);i++)
		cout<<x[i]<<" "<<y[i]<<endl;
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
a1 b1
a2 b2
a3 b3

a2-a1
a3-a2


b3-b2
b2-b1
*/