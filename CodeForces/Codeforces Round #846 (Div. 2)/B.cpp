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
	int n;
	vector<ll>p,pre;


	cin>>n;
	p.resize(n);
	pre.resize(n);

	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		pre[i]=(i>0?pre[i-1]:0)+p[i];
	}

	ll ans=1;
	for(int i=0;i<n-1;i++)
	{
		// cout<<i<<" "<<pre[i]<<" "<<pre[n-1]-pre[i]<<endl;
		ans=max(ans,__gcd(pre[i],pre[n-1]-pre[i]));
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
/*
6746328388800
6746328388800
*/