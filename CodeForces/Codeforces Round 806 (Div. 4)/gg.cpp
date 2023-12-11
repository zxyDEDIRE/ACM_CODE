/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e5+5;
ll p[maxn][35];
ll sum[maxn][35];
ll n,k;
void solve()
{
	cin>>n>>k;
	memset(p,0,sizeof(p));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		cin>>p[i][0];
		int cnt=0;
		ll t=p[i][0];
		while(t)
		{
			cnt++;
			t>>=1;
			p[i][cnt]=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<"YES"<<endl;
		for(int j=0;j<=5;j++)
		{
			//cout<<p[i][j]<<" ";
			sum[i][j]=sum[i-1][j]+p[i][j];
		}
		//cout<<endl;
	}

	ll ans=0;
	ll t=0;
	// for(int i=1;i<=n;i++)
	// 	cout<<sum[i][0]<<" ";
	// cout<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		//cout<<k<<" "<<(sum[n][t]-sum[i-1][t])-(sum[n][t+1]-sum[i-1][t+1])<<endl;
		//cout<<(sum[n][t]-sum[i-1][t])<<" "<<(sum[n][t+1]-sum[i-1][t+1])<<endl;
		if(k>=((sum[n][t]-sum[i-1][t])-(sum[n][t+1]-sum[i-1][t+1])))
		{
			t++;
			ans+=p[i][t];
		}
		else
		{
			ans+=p[i][t]-k;
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
85 60


43+30
57


85-57=28+

*/