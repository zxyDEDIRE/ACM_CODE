#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int mp[N];
int n,m;
int get(int x,int y)
{
	return (x-1)*m+y;
}
long long get1(long long x)
{
	return x*(x+1)/2;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long tp=get1(n)*get1(m);
		if(tp&1) {
			cout<<"NO\n";continue;
		}
		cout<<"YES\n";
		if(n<=m)
		{
			long long mo=1ll*((m+1)/2)*((m)/2+1);
			int l=0,r=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j+i-1<=n;j++)
				{
					long long res=get1(i);
					res+=get1(n)*(get1((m+1)/2-1)+get1(m/2));
					res+=mo*(n-i);
					if(res==tp/2) {
						l=j;r=j+i-1;break;
					}
				}
				if(l) break;
			}
			cout<<l<<" "<<r<<'\n';
		}
		else{

		}
	}

	return 0;
}