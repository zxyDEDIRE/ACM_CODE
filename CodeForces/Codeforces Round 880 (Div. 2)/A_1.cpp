#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],b[i]=0;
		sort(a+1,a+1+n);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			if(x==0)b[x]++;
			else
			{
				b[x-1]--;
				if(b[x-1]<0){
					flag=0;
				}
				b[x]++;
			}
		}
		if(flag==0)cout<<"No\n";
		else cout<<"Yes\n";
	}
	
	return 0;
}
