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
int n,k;
int f(int x)
{
	if(x==4)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(p[i]%2==0)cnt++;
		if(cnt>=2)return 0;
		return 2-cnt;
	}
	if(x==6)
	{
		int mi1=INF,mi2=INF;
		int ans=INF;
		for(int i=1;i<=n;i++)
		{
			int a=2-(p[i]%2);
			int b=3-(p[i]%3);
			if(a==2)a=0;
			if(b==3)b=0;
			ans=min(ans,a+mi2);
			ans=min(ans,b+mi1);
			mi1=min(mi1,a);
			mi2=min(mi2,b);
		}
		return ans;
	}
	return INF;
}
/*
1 2 3 4 5
*/
void solve()
{
	cin>>n>>k;
	int flag=0,ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]%k==0)flag=1;
		ma=max(ma,p[i]%k);
	}
	if(flag){
		cout<<0<<endl;
		return ;
	}
	//4 2 2
	//6 2 3
	int ans=k-ma;
	if(k==4)ans=min(ans,f(4));
	if(k==6)ans=min(ans,f(6));
	cout<<ans<<endl;
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
4 6
1 2 4 5

*/