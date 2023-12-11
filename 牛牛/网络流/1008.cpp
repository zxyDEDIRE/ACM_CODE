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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int n,m,sum;
bool check(int mid)
{
	int tot=mid*m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=min(p[i],mid);
	}
	return cnt>=tot;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	int l=0,r=sum,ans=l;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
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