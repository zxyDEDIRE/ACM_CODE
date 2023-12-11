#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll p[55];
void insert(ll num)
{
	for (int i=50;i>=0;i--)
	{
		if ((num&(1ll<<i))==0) continue;
		if (p[i]==0){p[i]=num;break;}
		num^=p[i];
	}
}
int main()
{
	int __;scanf("%d",&__);
	while(__--)
	{
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){ll num;scanf("%lld",&num);insert(num);}
			ll ans=0;
		for (int i=50;i>=0;i--)
			if ((ans^p[i])>ans) ans^=p[i];
		printf("%lld\n",ans);
	}
	
	return 0;
}