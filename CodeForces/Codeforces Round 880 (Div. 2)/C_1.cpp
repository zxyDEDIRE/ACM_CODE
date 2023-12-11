#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[4];
long long k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		for(int i=1;i<=3;i++)
		{
			int x;cin>>x;
			a[i].x=pow(10,x-1);
			a[i].y=pow(10,x)-1;
		}
		cin>>k;
		int flag=0;
		for(int i=a[1].x;i<=a[1].y;i++)
		{
			int l=a[3].x-i;
			int r=a[3].y-i;
			if(r<a[2].x||l>a[2].y)continue;
			l=max(l,a[2].x);
			r=min(r,a[2].y);
			if(k>(r-l+1))k-=(r-l+1);
			else
			{
				l=l+k-1;
				cout<<i<<" + "<<l<<" = "<<i+l<<"\n";
				flag=1;
				break;
			}
		}
		if(flag==0)cout<<-1<<"\n";
	}
}