#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,k,a[maxn];
void solve()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);

	map<int,bool> vis;
	map<int,int> mp;
	set<int> s;
	s.insert(-1);

	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x]=1;
		mp[x]=y;
		if(y==0)
			s.insert(x);
	}

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int p=*(--upper_bound(s.begin(),s.end(),a[i]))+1;
		ans+=a[i]-p;
		if(vis[p])
		{
			mp[p]--;
			if(mp[p]==0)
				s.insert(p);
		}
	}
	cout<<ans<<endl;
	if(ans&1)
		printf("Pico\n");
	else
		printf("FuuFuu\n");
	
}
signed main()
{
	int32_t T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}