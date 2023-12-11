#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+100;
bitset<maxn>vis;
int to[maxn];
set<int>a,b;
char p[maxn];
int n,m;
int ans=0;
MC
void solve()
{
	cin>>n>>m;
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;char ch;
			cin>>x>>ch;
			p[x]=ch;
			if(ch=='(')
			{
				auto fl=b.lower_bound(x);
				if(b.size()==0||fl==b.end()){
					ans^=x;
					a.insert(x);
				}
				else
				{
					int y=*fl;
				vis[x]=vis[y]=1;
				to[x]=y;
				to[y]=x;
				b.erase(y);
				ans^=y;
				}
				
			}
			else
			{
				auto fl=a.upper_bound(x);
				// fl--;
				if(a.size()==0||*(fl--)>x)
				{
					ans^=x;
					b.insert(x);
					continue;
				}
				int y=*fl;
				vis[x]=vis[y]=1;
				to[x]=y;
				to[y]=x;
				a.erase(y);
				ans^=y;
			}
		}
		else
		{
			int x;
			cin>>x;
			if(vis[x]==0)
			{
				ans^=x;
				if(p[x]=='(')a.erase(x);
				else b.erase(x);
			}
			else
			{
				ans^=to[x];
				if(p[x]=='(')b.insert(to[x]);
				else a.insert(to[x]);
			}

		}
		cout<<a.size()+b.size()<<" "<<ans<<endl;
	}
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	solve();
	return 0;
}