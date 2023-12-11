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
const int maxn=1e6;
ll a[maxn],b[maxn];
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=b[i]=0;
	ll ans=0;
	if(n%2==1)
	{
		for(int i=2;i<n;i+=2)
		{
			ll t=max(p[i-1],p[i+1]);
			t++;
			if(t>p[i])
			ans+=t-p[i];
		}
		cout<<ans<<endl;
		return ;
	}
	for(int i=2;i<n;i++)
	{
		if(i%2==0)
		{
			ll t=max(p[i-1],p[i+1]);
			t++;
			if(t>p[i])a[i]+=t-p[i]+a[i-1];
			else a[i]=a[i-1];
		}
		else a[i]=a[i-1];
	}
	for(int i=n-1;i>1;i--)
	{
		if(i%2==1)
		{
			ll t=max(p[i-1],p[i+1]);
			t++;
			//cout<<i<<" "<<t<<" "<<p[i]<<endl;
			if(t>p[i])b[i]+=t-p[i]+b[i+1];
			else b[i]=b[i+1];
		}
		else b[i]=b[i+1];
	}
	ll mi=min(a[n-1],b[3]);
	for(int i=2;i<n;i++)
	{
			mi=min(mi,a[i]+b[i+1]);
	}
	cout<<mi<<endl;

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
4 2 1 3 5 3  6  1
0 3 3 6 6 10 10 0 
0 3 3 0 0 0  0  0 

1
3
1 20 1
*/