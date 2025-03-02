#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int po[100];
int p[maxn];
int n;
signed main()
{
	for(int i=1;i<=48;i++)po[i]=i*i*i;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	int ans=0;
	for(int i=1;i<=n;)
	{
		if(i==n)break;
		int mi=LONG_LONG_MAX,fl=i+1;
		for(int j=i+1;j<=min(i+500,n);j++){
			int x=pow(j-i,3)*p[j];
			if(x<mi){
				mi=x;
				fl=j;
			}
		}
		ans+=mi;
		i=fl;
	}
	cout<<ans<<endl;
}
//1e5 50
