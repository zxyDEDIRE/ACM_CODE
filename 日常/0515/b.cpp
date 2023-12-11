#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
pii a[maxn];
int p[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i].first=p[i],a[i].second=i;
	sort(a+1,a+1+n,[&](pii x,pii y){return x.first<y.first;});
	for(int i=1;i<=n;i++)
		a[i].first=i;
	sort(a+1,a+1+n,[&](pii x,pii y){return x.second<y.second;});

	bitset<maxn>vis;
	int t=n;

	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i].first])continue;
		ans+=p[i];
		vis[t]=1;
		while(vis[t])t--;
	}
	cout<<ans<<endl;
}
