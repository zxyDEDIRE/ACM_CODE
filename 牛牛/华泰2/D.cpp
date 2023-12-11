#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int p[40];
int len[40];
int sum[40];
void init()
{
	p[1]=1;
	len[1]=6;
	for(int i=2;i<=26;i++)
	{
		if(i&1)
		{
			p[i]=p[i-1]*2;
			len[i]=len[i-1]+2;
		}
		else 
		{
			p[i]=p[i-1]*5;
			len[i]=len[i-1]+1;
		}
	}
	sum[1]=4*len[1];
	for(int i=2;i<=26;i++)
	{
		sum[i]=sum[i-1]+(p[i+1]-p[i])*len[i];
		// cout<<sum[i]<<endl;
	}
}
void solve()
{
	int n;
	cin>>n;
	int l=0;
	for(int i=1;i<=26;i++)
		if(n<=sum[i]){
			l=i;
			break;
		}
	// cout<<l<<endl;
	n-=sum[l-1];
	// cout<<"n "<<n<<endl;
	int x=n/len[l];
	int y=n%len[l];
	// cout<<"x "<<x<<" y "<<y<<endl;
	int z=p[l]+x;
	// cout<<"z "<<z<<endl;
	if(y==0)
	{
		cout<<","<<endl;
	}
	else
	{
		// z++;
		string ans=to_string(z) + "+"+to_string(z)+"="+to_string(z*2)+",";
		// cout<<ans<<endl;
		cout<<ans[y-1]<<endl;
	}
}
signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	init();
	int T;cin>>T;
	while(T--)
		solve();
	return 0;
}
/*
1+1=1,2+2=4,3+3=6,4+4=8,5+5=10,6+6=12,7+7=14,8+8=16,9+9=18,10+10=20;
10+1=20

10+10=20
5+5=10
*/