#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];

void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			for(int j=l;j<=r;j++)
			{
				a[j]=(a[j]<x)?x-a[j]:x+a[j];
			}
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			long long ans=0;
			for(int j=l;j<=r;j++) ans+=a[j];
			// printf("%lld\n",ans);
		}
	}
}

int main()
{
	freopen("C:\\Users\\tob\\Desktop\\a\\b\\1011\\1011.in","r",stdin);
	int t=1;
	scanf("%d",&t);
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
