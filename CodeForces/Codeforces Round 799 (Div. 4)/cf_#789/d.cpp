#include<bits/stdc++.h>
using namespace std;
const int N=1007;
int p[N];
struct node
{
	int val;
	int id;
}t[N];
bool cmp1(node a,node b)
{
	return a.val<b.val;
}
bool cmp2(node a,node b)
{
	return a.id<b.id;
}
int find(int x,int l,int r)
{
	int ans=l;
	while(l<r-1)
	{
		int mid=l+r>>1;
		if(t[mid].val>=x)ans=l,l=mid;
		else r=mid-1;
	}
	if(t[ans-1].val>=x)return ans-1;
	else return ans;
}
void slov()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],t[i].val=p[i],t[i].id=i;
	long long ans=0;
	for(int b=2;b<=n;b++)
	{
		for(int c=b+1;c<n;c++)
		{
			sort(t+1,t+b,cmp1);
			sort(t+2+c,t+1+n,cmp1);
			int l=1,r=b-1;
			int id1=0;
			if(l<=r)
			{
				id1=find(p[c],l,r);
			}
			id1--;
			l=c+1,r=n;
			int id2=0;
			if(l<=r)
			{
				id2=find(p[b],l,r);
			}
			id2--;
			if(id1>0&&id2>c)
			{
				ans+=1ll*id1*(id2-c);
			}
			sort(t+1,t+1+n,cmp2);
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		slov();
	}
}