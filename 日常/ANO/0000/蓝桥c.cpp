#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n,m,len,a,b;
signed main()
{
	cin>>n>>m;len=n+m+1;
	for(int i=1;i<=len;i++){
		cin>>p[i];
		if(p[i]<0)b++;
		else a++;
	}
	sort(p+1,p+1+len);
	int ans=p[len];
	if(m>b)
	{
		ans-=p[1];
		for(int i=2;i<len;i++)ans+=abs(p[i]); 
	}
	else if(m==0)
	{
		for(int i=1;i<len;i++)ans+=p[i];
	}
	else if(m<=b)
	{
		for(int i=1;i<len;i++)ans+=abs(p[i]);     
	}
	cout<<ans<<endl;
}
/*
2 1
-1 -2 -3 -4


2 7
-1 0 1 2 3 4 5 6 7 8

3 0
-1 0 0 1


2 1
-3 -2 1 5


1 1
1 2 3

*/