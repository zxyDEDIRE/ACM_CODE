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
ll mp[222][222];
ll n,t;
void solve()
{
	cin>>n;
	n%=t;
	if(n==0){
		cout<<0<<endl;
		return ;
	}
	for(int i=0;i<=22;i++)
		for(int j=0;j<=22;j++)
			mp[i][j]=-1;
	for(int i=0;i<20;i++)
		if((1ll<<i)>=n)
			mp[20][i]=n-(1ll<<i);
	for(int i=0;i<19;i++)
		mp[i][i+1]=1;
	mp[19][0]=1;



}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	t=(1ll<<20);
	while(__--)
		solve();
	return 0;
}
/*
*/