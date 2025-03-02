#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e6;
int a[maxn],b[maxn],c[maxn];
int p[maxn];
int n;
int fp(int b,int pp)
{
	int res=1;
	while(pp)
	{
		if(pp&1)res=(res*b)%mod;
		pp>>=1;
		b=(b*b)%mod;
	}
	return res;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i],p[b[i]]=i;
	for(int i=1;i<=n;i++)cin>>c[i];
	int ans=0;
	bitset<maxn>vis;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(a[i]==b[i])continue;

		int r=a[i];
		flag=0;
		while(1)
		{
			r=p[r];
			if(c[r])flag=1;
			vis[r]=1;
			r=a[r];
			if(r==a[i])break;
		}
		if(!flag)ans++;
	}
	cout<<fp(2ll,ans)<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
1
7
1 2 3 4 5 6 7
2 3 1 7 6 5 4
2 0 1 0 0 0 0
*/