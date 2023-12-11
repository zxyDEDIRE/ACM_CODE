/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	ll n,ans=1;
	map<ll,ll>mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				while(x%j==0)
					mp[j]++,x/=j;
			}
		if(x>1)mp[x]++;
	}
	for(auto [x,y]:mp)
	{
		int t=1;
		while(y--)t=(t*x+1)%INF;
		ans=(ans*t)%INF;
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 4 8
1=1*2+1=3
3=3*2+1=7

*/