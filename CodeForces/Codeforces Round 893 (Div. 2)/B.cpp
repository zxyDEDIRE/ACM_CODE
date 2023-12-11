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
ll p[maxn];
ll n,m,d;
int f(int x,int y){
	ll len=max(0ll,p[y]-p[x]-1);
	len=floor(len/d);
	return len;
}
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	ll ans=1;
	p[0]=1;
	for(int i=1;i<=m;i++){
		ans+=f(i-1,i);
		if(p[i]!=1)ans++;
	}

	p[++m]=n+1;
	ans+=f(m-1,m);
	
	ll res=ans,t=1,cnt=0;
	for(int i=1;i<m;i++)
	{
		ll now=ans-f(i-1,i)-f(i,i+1)-1+f(i-1,i+1);
		if(p[i]==1)now++;
		if(now<res)res=now,t=i,cnt=1;
		else if(now==res)cnt++;
	}
	cout<<res<<" "<<cnt<<endl;
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
1 2 3 4 5 6 7 8
1   1   1   1 1
*/