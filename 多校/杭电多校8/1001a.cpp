#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxn=1e6+7;
int n,m,k,ans;
void solve()
{
	cin>>n>>m>>k;ans=0;
	for(int i=1;i<=n;i++)
	{
		//当前有i段
		//最好是平均分这i段，最短的一段长度为n/i
		int x=n/i;
		//要满足这一段的面积够k的话
		if(x*m>=k)
		{
			//考虑m要分成几段，1段肯定够
			int y=k/x;
			if(x*y<k)
				y++;
			//边长至少为y
			int j=m/y;//可以分成j段
			ans=max(ans,i+j-2);
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	return 0;
}