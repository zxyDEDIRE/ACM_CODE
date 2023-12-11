#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using pdd=pair<double,double>;
const int maxn=1e6+100;
pdd p[maxn];
int n;
pdd center(pdd a,pdd b,pdd c={0,0})
{
	double a1 = b.first - a.first, b1 = b.second - a.second, c1 = (a1*a1 + b1*b1)/2;
  	double a2 = c.first - a.first, b2 = c.second - a.second, c2 = (a2*a2 + b2*b2)/2;
  	double d = a1*b2 - a2*b1;
  	return {a.first + (c1*b2 - c2*b1)/d, a.second + (a1*c2 -a2*c1)/d};
}
void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	int ans=2;
	for(int i=1;i<=n;i++)
	{
		map<pdd,int>mp;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(p[i].first*p[j].second-p[i].second*p[j].first)>(1e-10))
			{
				auto now=center(p[j],p[i],{0,0});
				mp[now]++;
				// cout<<i<<endl;
				// cout<<now.first<<" "<<now.second<<" "<<mp[now]<<endl;
				ans=max(ans,mp[now]+1);
			}
		}
	}
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