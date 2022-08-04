#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll n,k,x,ans;
void solve()
{
	cin>>n>>k;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ans+=x/k;
		p[i]=x%k;
	}
	sort(p+1,p+1+n);
	int l=1,r=n;
	while(l<r)
	{
		if(p[l]+p[r]>=k)ans++,r--;
		l++;
	}
	cout<<ans<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}