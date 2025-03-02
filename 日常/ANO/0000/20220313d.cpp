#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int b[maxn],c[maxn],bb[maxn],cc[maxn];
int step[maxn],ans[maxn];
int n,mi=maxn,cnt;
void dfs(int x,int num,int an,int t)
{
//	cout<<x<<endl;
	if(t==n*2)
	{
		if(an<mi)
		{
			mi=an;
			for(int i=1;i<=n*2;i++)
				ans[i]=step[i];
		}
		return ;
	}
	if(num==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(cc[i])continue;
			cc[i]=1;
			step[++cnt]=c[i];
			dfs(c[i],num+1,an+abs(x-c[i]),t+1);
			cc[i]=0;cnt--;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(cc[i])continue;
			cc[i]=1;
			step[++cnt]=c[i];
			dfs(c[i],num+1,an+abs(x-c[i]),t+1);
			cc[i]=0;cnt--;
		}
		for(int i=1;i<=n;i++)
		{
			if(bb[i])continue;
			bb[i]=1;
			step[++cnt]=b[i];
			dfs(b[i],num-1,an+abs(x-b[i]),t+1);
			bb[i]=0;cnt--;
		}
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,0,0);
	cout<<mi<<endl;
	for(int i=1;i<=n*2;i++)
		cout<<ans[i]<<" ";
}
