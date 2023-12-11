void solve()
{
	int n,k;
	cin>>n>>k;
	map<int,int>pre;
	map<int,int>ne;
	for(int i=1;i<=n;i++)
		cin>>u[i];
	for(int i=1;i<=n;i++)
		ne[u[i]]=i;
	for(int i=n;i>=1;i--)
	{
		pre[u[i]]=i;
	}
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		if(pre[a]==0||ne[b]==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(pre[a]<=ne[b])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}