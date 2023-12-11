#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n;
int merge_sort(int p[],int l,int r)
{
//	cout<<l<<" "<<r<<endl;
	if(l>=r)return 0;
	int t=0;
	int mid=l+r>>1;
	t=merge_sort(p,l,mid)+merge_sort(p,mid+1,r);
	int temp[r-l+1];
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=mid-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=mid)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	int res=merge_sort(p,1,n);
	cout<<res;
}
