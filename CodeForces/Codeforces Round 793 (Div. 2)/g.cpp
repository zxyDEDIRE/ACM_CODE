#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll mod=1e9+7;
const int maxn=1e5+7;
int n;
ll x;
queue<pii> q;
map<ll,bool> mp;
bool vis[10];
int getnum(ll k)
{
	for(int i=0;i<10;i++)
		vis[i]=0;
	if(k==0)
		return 1;
	int res=0;
	while(k)
	{
		res++;
		vis[k%10]=1;
		k/=10;
	}
	return res;
}
void solve()
{
	cin>>n>>x;
	q.push({x,0});
	mp[x]=1;
	while(q.size())
	{
		auto [now,step]=q.front();
		q.pop();

		int k=getnum(now);
		if(k==n)
		{
			cout<<step<<endl;
			return;
		}
		if(k>n)
			break;
		for(int i=9;i>1;i--)
			if(vis[i])
			{
				if(mp[now*i])
					continue;
				mp[now*i]=1;
				q.push({now*i,step+1});
			}
	}
	cout<<-1<<endl;
}

int main()
{
	solve();
	return 0;
}