#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int maxn=1e4;
int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}
signed main()
{
	
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%lld/%lld",&x,&y);
		if(i==1)
		{
			a=x,b=y;

		}
		else
		{
			int v=lcm(y,b);
			int u=a*(v/b)+x*(v/y);
			a=u;
			b=v;
		}
		int t=__gcd(a,b);
		a/=t;
		b/=t;
	}
	int s=a/b;
	int flag=0;
	if(s!=0)cout<<s,flag=1;
	int t=__gcd(a,b);
			a/=t;
			b/=t;
	if(a%b!=0){
		if(flag)cout<<" ";
		cout<<a<<"/"<<b<<endl;
	}
}
void solve()
{

}