#include<bits/stdc++.h>
using namespace std;
using ll=long long;
long long a,b,c;
bool check(long long x,long long y,long long z)
{
	return x%y==a&&y%z==b&&z%x==c;
}

void solve()
{
	cin>>a>>b>>c;
	if(a==0&&b==0&&c==0)
	{
		cout<<"YES\n";
		cout<<1<<" "<<1<<" "<<1<<'\n';
		return;
	}
	if(a==0&&b==0)
	{
		cout<<"YES\n";
		cout<<c*6<<" "<<c*3<<" "<<c<<'\n';return;
	}
	else if(a==0&&c==0)
	{
		cout<<"YES\n";
		cout<<2*b<<" "<<b<<" "<<6*b<<'\n';return;
	}
	else if(b==0&&c==0)
	{
		cout<<"YES\n";
		cout<<a<<" "<<a*6<<" "<<3*a<<'\n';return;
	}
	else if(a==0&&b==c)
	{
		cout<<"YES\n";
		cout<<2*b<<" "<<b<<" "<<3*b<<'\n';return;
	}
	else if(b==0&&a==c)
	{
		cout<<"YES\n";
		cout<<3*a<<" "<<2*a<<" "<<a<<'\n';return;
	}
	else if(c==0&&b==a)
	{
		cout<<"YES\n";
		cout<<a<<" "<<a*3<<" "<<2*a<<'\n';return;
	}
	long long x=a,z=c+a,y=a+b+c;
	if(x!=0&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';return;
	}
	x=a+b,y=b,z=a+b+c;
	if(y&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';return;
	}
	z=c;y=c+b;x=a+b+c;
	if(z&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';return;
	}
	cout<<"NO\n";
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
1 0 1
3 2 1

2 0 2
6 4 2
*/