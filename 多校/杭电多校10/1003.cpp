/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
ll a[maxn],b[maxn];
ll p[maxn];
int n;
int A()//di 1
{
	for(int i=1;i<=n;i++)
		p[i]=a[i];
	int ans=0;
	p[0]=p[2];
	for(int i=1;i<=n;i++)
	{
		p[n+1]=p[n-1];
		if(i&1)
		{
			int x=min(p[i-1],p[i+1]);
			if(p[i]>=x)
			{
				ans+=p[i]-x+1;
				p[i]=x-1;
			}
		}
		else
		{
			int x=max(p[i-1],p[i+1]);
			if(p[i]<=x)
			{
				ans+=x-p[i]+1;
				p[i]=x+1;
			}
		}
	}
	return ans;
}
int B()
{
	for(int i=1;i<=n;i++)
		p[i]=a[i];
	int ans=0;
	p[0]=p[2];
	for(int i=2;i<=n;i++)
	{
		p[n+1]=p[n-1];
		if(i&1)
		{
			int x=min(p[i-1],p[i+1]);
			if(p[i]>=x)
			{
				ans+=p[i]-x+1;
				p[i]=x-1;
			}
		}
		else
		{
			int x=max(p[i-1],p[i+1]);
			if(p[i]<=x)
			{
				ans+=x-p[i]+1;
				p[i]=x+1;
			}
		}
	}
	return ans;
}
int C()
{
	for(int i=1;i<=n;i++)
		p[i]=a[i];
	int ans=0;
	p[0]=p[2];
	for(int i=1;i<=n;i++)
	{
		p[n+1]=p[n-1];
		if(i%2==0)
		{
			int x=min(p[i-1],p[i+1]);
			if(p[i]>=x)
			{
				ans+=p[i]-x+1;
				p[i]=x-1;
			}
		}
		else
		{
			int x=max(p[i-1],p[i+1]);
			if(p[i]<=x)
			{
				ans+=x-p[i]+1;
				p[i]=x+1;
			}
		}
	}
	return ans;
}
int D()
{
		for(int i=1;i<=n;i++)
		p[i]=a[i];
	int ans=0;
	p[0]=p[2];
	for(int i=2;i<=n;i++)
	{
		p[n+1]=p[n-1];
		if(i%2==0)
		{
			int x=min(p[i-1],p[i+1]);
			if(p[i]>=x)
			{
				ans+=p[i]-x+1;
				p[i]=x-1;
			}
		}
		else
		{
			int x=max(p[i-1],p[i+1]);
			if(p[i]<=x)
			{
				ans+=x-p[i]+1;
				p[i]=x+1;
			}
		}
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<min({A(),B(),C(),D()})<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 1 4 5 1 4
1 5 4 5 1 4
*/