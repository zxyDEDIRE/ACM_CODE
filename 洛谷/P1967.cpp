/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],a[maxn],b[maxn];
int aa[maxn],bb[maxn];
ll n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	a[1]=p[1];
	aa[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]<a[i-1])
		{
			a[i]=p[i];
			aa[i]=i;
		}
		else
		{
			a[i]=a[i-1];
			aa[i]=aa[i-1];
		}
	}
	b[n]=p[n];
	bb[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(p[i]<b[i+1])
		{
			b[i]=p[i];
			bb[i]=i;
		}
		else
		{
			b[i]=b[i+1];
			bb[i]=bb[i+1];
		}
	}
	for(int i=2;i<n;i++)
	{
		if(a[i-1]<p[i]&&p[i]>b[i+1]){
			cout<<"YES"<<endl;
			cout<<aa[i-1]<<" "<<i<<" "<<bb[i+1]<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}