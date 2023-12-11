#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
int n,m;
int mp[N],cnt;
int a[N];
long long get(long long n)
{
	return n*(n+1)/2;
}
long long op;

bool dfs(int m,int o,long long s)
{
	if(s+m==op)
	{
		while(m--) mp[++cnt]=1;
		return true;
	}
	if(o==1) return false;
	if(s>op) return false;
	if(s+get(m)<op) return false; 
	if(m==0)
	{
		if(s==op) return true;
		else return false;
	}
	if(s==op) return false;
	int l=1,r=min(m,o);
	while(l<r)
	{
		int mi=(l+r+1)>>1;
		if(get(mi)+s+m-mi<=op) l=mi;
		else r=mi-1;
	}
//	cout<<get(l)+m-l<<" "<<m-l<<" "<<op<<'\n';
	for(int i=r;i>=1;i--)
	{
		mp[++cnt]=i;
		if(dfs(m-i,i,s+get(i)))
		{
			return true;
		}
		--cnt;
	}
	return false;
}
 
void solve()
{
	
	cin>>n>>m;
	cnt=0;
	long long tp=get(n)*get(m);
	if(tp&1) {
		cout<<"No\n";return;
	}
	int flag=0;
	if(get(n)%2==0)
	{
		flag=1;
		swap(n,m);
	}
	cout<<"Yes\n";
	op=get(m)/2;
	dfs(m,m,0);
	int f=0;
	int ot=0;
	for(int i=1;i<=cnt;i++)
	{
		while(mp[i]--)
		{
			a[++ot]=f;
		}
		f^=1;
	}
	if(flag)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<a[i]<<" ";
			}
			cout<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<a[j]<<" ";
			}
			cout<<'\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}