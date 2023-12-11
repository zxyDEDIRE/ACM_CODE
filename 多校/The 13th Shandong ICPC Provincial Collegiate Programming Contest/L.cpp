#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,x,y;

void dfs(int tp,int l,int r,int ll,int rr)
{
	if(tp==n+1) return;
	int x,y;
	x=l-1,y=r-1;
	if(x>=1&&y>=1)
	{
		cout<<x<<" "<<y<<" "<<ll-x<<" "<<rr-y<<'\n';
		dfs(tp+1,x,y,ll,rr);
		return;
	}
	x=l-1,y=rr+1;;
	if(x>=1&&y<=n)
	{
		cout<<x<<" "<<y<<" "<<ll-x<<" "<<r-y<<'\n';
		dfs(tp+1,x,r,ll,y);
		return;
	}
	x=ll+1,y=r-1;
	if(x<=n&&y>=1)
	{
		cout<<x<<" "<<y<<" "<<l-x<<" "<<rr-y<<'\n';
		dfs(tp+1,l,y,x,rr);
		return;
	}
	x=ll+1,y=rr+1;
	if(x<=n&&y<=n)
	{
		cout<<x<<" "<<y<<" "<<l-x<<" "<<r-y<<'\n';
		dfs(tp+1,l,r,x,y);
		return;
	}
	
}

void solve()
{
	cin>>n>>x>>y;
	cout<<"Yes\n";
	cout<<n-1<<'\n';
	dfs(2,x,y,x,y);

}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
