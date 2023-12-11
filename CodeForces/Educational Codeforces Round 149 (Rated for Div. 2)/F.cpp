const int N=3e5+10;
int a[N];
int n,k;
long long dp[N],pd[N];
long long check(int x)
{
	priority_queue<int>q,p;
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1e18;
		q.push(a[i]);
		res+=a[i];
		while(q.size()>x)
		{
			res-=q.top();
			q.pop();
		}
		if(q.size()==x) dp[i]=res;
	}
	res=0;
	for(int i=n;i>=1;i--)
	{
		pd[i]=1e18;
		p.push(a[i]);
		res+=a[i];
		while(p.size()>k-x) 
		{
			res-=p.top();
			p.pop();
		}
		if(p.size()==k-x) pd[i]=res;
	}
	long long ans=1e18;
	for(int i=1;i<n;i++)
	{
		ans=min(ans,max(dp[i],pd[i+1]));
	}
	if(x==k) ans=min(ans,dp[n]);
	return ans;
}
