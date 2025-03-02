#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
int k,c,cnt=0;
void solve()
{
	int n,mp[11][11],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;cin>>x;
			if(i==j)ans+=x;
			else if(i==(n-j+1))ans+=x;
			else if(i==(n/2+1))ans+=x;
			else if(j==(n/2+1))ans+=x;
		}
	}
	cout<<ans<<endl;
}
signed main(){
//	int n=3;
//	cout<<__builtin_popcount(n);
//	int x=__builtin_popcount(n);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}