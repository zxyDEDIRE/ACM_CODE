#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
unordered_map<int,int>num;
unordered_map<int,int>p;
int n;
int find(int r)
{
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n)
	{
		num.clear();
		p.clear();
		int ma=1;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			if(!p[x])p[x]=x,num[x]=1;
			if(!p[y])p[y]=y,num[y]=1;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				p[fb]=fa;
				num[fa]+=num[fb];
				ma=max(ma,num[fa]);
			}
		}
		cout<<ma<<endl;
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}