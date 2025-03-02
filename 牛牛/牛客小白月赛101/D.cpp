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
ll t[maxn];
ll sum[maxn];
ll p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum[i]=sum[i-1]+p[i];
	map<int,int>mp;
	for(int i=1;;i++)
	{
		if(i*i>1e9)break;
		mp[i*i]=1;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ll tmp=sum[j]-sum[i-1];
			if(mp.count(tmp))
			{
				t[i]++;
				t[j+1]--;
			}
		}
	}
	for(int i=2;i<=n;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=q;i++)
	{
		int x;cin>>x;
		cout<<t[x]<<endl;
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
/*

1 2 3 4  5
1 2 2 1  0
1 1 0 -1 -1

1 3 3 1  0
1 2 0 -2 -1

0 0 0 0 0
1

1 -1 0 0 0
1 0 0 0 0 0


*/