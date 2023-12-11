#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
bitset<maxn>vis;
int p[maxn];
int n;
void solve()
{
	set<int>s;
	vis.reset();
	int ma=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],s.insert(p[i]),ma=max(ma,p[i]);
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		for(int j=i+1;j<=n;j++)
		{
			if(vis[j])continue;
			int y=p[j];
			int z=y*2-x;
			if(z>ma)break;
			if(s.count(z))
			{
				ans++;
				vis[j]=1;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n)
		solve();
} 
