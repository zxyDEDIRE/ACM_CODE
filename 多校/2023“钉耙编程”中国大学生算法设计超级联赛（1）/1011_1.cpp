#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];

void solve()
{
	int n,m;
	n=1e5;m=1e5;
	for(int i=1;i<=n;i++)
	{
		a[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		if(i&1) op=1;
		else op=2;
		if(op==1)
		{
			int l,r,x;
			l=1,r=n;x=1;
			for(int j=l;j<=r;j++)
			{
				a[j]=(a[j]<x)?x-a[j]:x+a[j];
			}
		}
		else{
			int l,r;
			l=1,r=n;
			long long ans=0;
			for(int j=l;j<=r;j++) ans+=a[j];
			// printf("%lld\n",ans);
		}
	}
}

int main()
{
	int t=1;
	while(t--)
	{
		clock_t start, finish;
		start = clock();
		/*******代码*******/
		solve();
		/****************/
		finish = clock();
		cout << "the time cost is" <<\
		double(finish - start) / CLOCKS_PER_SEC;
	}
	return 0;
}
