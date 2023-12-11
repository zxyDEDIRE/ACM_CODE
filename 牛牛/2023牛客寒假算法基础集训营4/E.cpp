
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll h[maxn];
ll v[maxn];
ll n,t,a;
void NO(){cout<<-1<<endl;}
void solve()
{
	cin>>n>>t>>a;
	for(int i=1;i<=n;i++)
		cin>>h[i]>>v[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll x=h[i];
		ll y=v[i];
		if(y*t>=a)
		{
			if(x<=a)ans++;
			else return NO();
		}
		else
		{
			ll yu=a-(y*t);
			x-=a;ans++;
			if(x>0)
			{
				ans+=((x+yu-1)/yu)*t;
			}
		}
		if(i!=n)ans+=t-1;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 2 1
1 0
1 0
1
3
5


*/