#include<bits/stdc++.h>
using namespace std;
using ll=long long;
long long a,b,c;
bool check(long long x,long long y,long long z)
{
	return x%y==a&&y%z==b&&z%x==c;
}
struct node{
	ll x,y,z;
};
node solve()
{
	// cin>>a>>b>>c;
	if(a==0&&b==0&&c==0)
	{
		cout<<"YES\n";
		cout<<1<<" "<<1<<" "<<1<<'\n';
		return {1,1,1};
		// return;
	}
	if(a==0&&b==0)
	{
		cout<<"YES\n";
		cout<<c*6<<" "<<c*3<<" "<<c<<'\n';//return;
		return {c*6,c*3,c};
	}
	else if(a==0&&c==0)
	{
		cout<<"YES\n";
		cout<<2*b<<" "<<b<<" "<<6*b<<'\n';//return;
		return {2*b,b,b*6};
	}
	else if(b==0&&c==0)
	{
		cout<<"YES\n";
		cout<<a<<" "<<a*6<<" "<<3*a<<'\n';//return;
		return {a,a*6,a*3};
	}
	long long x=a,z=c+a,y=a+b+c;
	if(x!=0&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';//return;
		return {x,y,z};
	}
	x=a+b,y=b,z=a+b+c;
	if(y&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';//return;
		return {x,y,z};
	}
	z=c;y=c+b;x=a+b+c;
	if(z&&check(x,y,z))
	{
		cout<<"YES\n";
		cout<<x<<" "<<y<<" "<<z<<'\n';//return;
		return {x,y,z};
	}
	return {-1,-1,-1};
	cout<<"NO\n";
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(0));
	while(1)
	{
		a=0;
		b=rand()%1000;
		c=rand()%10;
		auto [x,y,z]=solve();
		if(x==-1||(x%y==a&&y%z==b&&z%x==c));
		else {
			cout<<endl;
			cout<<a<<" "<<b<<" "<<c<<endl;
			cout<<"NO"<<endl;
			return 0;
		}
	}
	return 0;
}