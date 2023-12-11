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
#define p(x) array<int,x>
using ull=unsigned l ong long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll division_block(ll n){
    ll res = 0;
    for(ll l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        // cout<<r<<endl;
        res += n / l * (r - l + 1);
    }
    return res;
}
void solve()
{
	int n,L,R;
	// cin>>n>>L>>R;
	// cin>>n;
	division_block(n);
	// int l=1,r=n,ans=n;
	// for(int i=1;i<=n;i++)
	// 	cout<<n/i<<" ";
	// cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}