#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
struct node{
	int x,y;
}a[maxn];
int dpa[maxn];
int dpb[maxn];
int p[maxn];
int n,lena,lenb;
bool cmpa(node a,node b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
bool cmpb(node a,node b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;

	sort(a+1,a+1+n,cmpa);
	for(int i=1;i<=n;i++)p[i]=a[i].y;
	dpa[0]=1e9;
	lena=0;
	for(int i=1;i<=n;i++)
	{
		if(dpa[lena]>p[i])dpa[++lena]=p[i];
		else
		{
			int fl=upper_bound(dpa+1,dpa+1+lena,p[i],greater<int>() )-dpa;
			dpa[fl]=p[i];
		}
	}

	sort(a+1,a+1+n,cmpb);
	for(int i=1;i<=n;i++)p[i]=a[i].x;
	dpb[0]=1e9;
	lenb=0;
	for(int i=1;i<=n;i++)
	{
		if(dpb[lenb]>p[i])dpb[++lenb]=p[i];
		else
		{
			int fl=upper_bound(dpb+1,dpb+1+lenb,p[i],greater<int>() )-dpb;
			dpb[fl]=p[i];
		}
	}

	cout<<min(lena,lenb)<<endl;
}