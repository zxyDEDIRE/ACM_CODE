/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n;
void solve()
{
	// 31 3
	// 365 1
	cin>>n;
	ll x=n%7;
	ll y=n/7;
	ll mi=1e18;
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=90;j++)
		{
			ll a=i*1;
			ll b=j*3; 
			ll m=n;
			ll cnt=0;
			if(365*i+31*j<=n&&((a+b)%7)==x)
			{
				m-=365*i;
				m-=31*j;
				cnt=i+j;
				if(m>=7*365)
				{
					ll xx=m/(7*365);
					m-=xx*7*365;
					cnt=cnt+xx;
				}
				cnt+=m/7;
				mi=min(mi,cnt);
				//cout<<i<<" "<<j<<" "<<mi<<endl;
			}
		}
	}
	if(mi==1e18)cout<<-1<<endl;
	else cout<<mi<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
51 17

1 38


365
*/