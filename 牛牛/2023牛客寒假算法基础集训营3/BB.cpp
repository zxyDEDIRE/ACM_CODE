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
	int n;
	cin>>n;
	n=1e18;
	if(n==1){cout<<1<<endl;return ;}
	if(n==2){cout<<-1<<endl;return ;}
	int x=(n+1)/2;
	int l=1,r=n,ans=1;
	auto ok=[&](int k)->bool{
		int num=k+(k-x)*2;
		if(num>n)return false;
		return true;
	};
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(ok(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(ok(ans+1))ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}