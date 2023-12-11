/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int maxn=1e6+100;
int mp[maxn];
int p[maxn];
int n,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],mp[p[i]]++;
	for(int i=0;i<=1000;i++)
	{
		if(mp[i])
		{
			int t=abs(i+i-1000);
			ans+=(1+mp[i])*t*mp[i]/2;
		}
		else
		{
			for(int j=i+1;j<=1000;j++){
				int t=abs(i+j-1000);
				ans+=mp[i]*mp[j]*t;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
500 499 501


499
*/