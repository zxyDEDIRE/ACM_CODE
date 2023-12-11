#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
const int N=1e3;
int p[maxn];
int a[maxn];
int n,k;
void solve()
{
	memset(p,0,sizeof(p));
	cin>>n>>k;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int m=a[i];
		int t=1;
		while(m)
		{
			p[t]+=(m%2);
			t++;
			m>>=1;
		}
		ma=max(ma,t);
	}
	for(int i=31;i>=1;i--)
	{
		int x=n-p[i];
		if(x<=k)p[i]=n,k-=x;
	}
	long long ans=0;
	for(int i=1;i<=31;i++)
		if(p[i]==n)ans+=pow(2,i-1);
	cout<<ans<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}