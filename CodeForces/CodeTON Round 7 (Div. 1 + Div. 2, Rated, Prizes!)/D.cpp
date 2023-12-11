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
int pre[maxn];
int n,q;
void solve()
{
	// cin>>n>>q;
	n=13;q=8;

	for(int i=1;i<=n;i++)
	{
		// cin>>a[i];
		a[i]=(rand()%2==0?1:2);
		a[1]=2;
		pre[i]=pre[i-1]+a[i];
	}
	set<int>s;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			s.insert(pre[j]-pre[i-1]);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=pre[n];i++)
		if(!s.count(i)){
			cout<<i<<" ";
		}
	cout<<" "<<pre[n]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
13 3
2 2 2 1 1 2 1 2 1 1 2 2 2
1 16
1 18
1 20
16 18 20  21
*/