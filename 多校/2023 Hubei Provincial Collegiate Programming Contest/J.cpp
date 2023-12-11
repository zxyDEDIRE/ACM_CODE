#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;

int a[N];
long long sum[N];
long long mp[N];
int id[N];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>0) return true;
		else if(sum[i]<0) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(sum[n]<0||check())
	{
		cout<<-1;return 0;
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		id[i]=x;
		if(sum[i]>sum[x]) x=i; 
	}
	long long ans=n-1;
	int op=0;
	long long pp=0;
	for(int i=n;i>=2;i--)
	{
		if(sum[i]>=0)
		{
			if(i==op) pp=0;
			continue;
		}
		else{
			pp+=sum[i];
			if(pp<0)
			{
				long long t=(abs(pp)+sum[id[i]]-1)/(sum[id[i]]);
				ans+=t;
				pp+=t*sum[id[i]];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}