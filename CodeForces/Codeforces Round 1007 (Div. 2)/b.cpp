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
int p[maxn];
int n;
bool q(ll y){
	ll x=floorl(sqrtl(y));
	if(x*x == y)return true;
	return false;
}
void solve()
{
	cin>>n;
	if(q(1ll*n*(n+1)/2)){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	ll sum=0;
	for(int i=1;i<n;i++)
	{
		if(q(sum+p[i]))swap(p[i],p[i+1]);
		sum+=p[i];
		cout<<p[i]<<" ";
	}
	cout<<p[n]<<endl;
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