#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6;
ll n,res;
ll p[maxn];
ll merge_sort(ll p[],ll l,ll r)
{
	if(l>=r)return 0;
	ll t=0;
	ll m=l+r>>1;
	t+=merge_sort(p,l,m);t+=merge_sort(p,m+1,r);
	cout<<l<<" "<<r<<endl;
	ll k=0,i=l,j=m+1;
	ll temp[r-l+2];
	while(i<=m&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=m-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=m)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	res=merge_sort(p,1,n);
	cout<<res;
}