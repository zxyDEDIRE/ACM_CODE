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
	ll l,r;
	cin>>l>>r;
	ll len=r-l; 
	ll ans=0;
	auto f=[&](ll i)->ll{
		return l+((l%i)==0?0:(i-(l%i)))+i;
	};
	auto add=[&](ll x,ll y)->ll{
		if(f(x)>r)return (f(y)<=r);
		ll L=x,R=y,res=L;
		while(L<R-1)
		{
			ll mid=(L+R)/2;
			if(f(mid)<=r)res=mid,L=mid;
			else R=mid;
		}
		while(res+1<=y&&f(res+1)<=r)res++;
		ll ans=res-x+1;
		if(res!=y&&f(y)<=r)ans++;
		return ans;
	};
	for(ll i=len;i>=1;i--)
	{
		ll x=i; 
		ll y=(l/(l/x+1)+1);
		ans+=add(y,x);
		i=y;
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
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
2 11
2 12
2 13
2 14
2 15
3 4
3 5
3 6
3 7
3 8
3 9
3 10
3 11
3 12
3 13
3 14
3 15
4 5
4 6
4 7
4 8
4 9
4 10
4 11
4 12
4 13
4 14
4 15
5 6
5 7
5 8
5 9
5 10
5 11
5 12
5 13
5 14
5 15
6 7
6 8
6 9
6 10
6 11
6 12
6 13
6 14
6 15
7 8
7 9
7 10
7 11
7 12
7 13
7 14
7 15
8 9
8 10
8 11
8 12
8 13
8 14
8 15
9 10
9 11
9 12
9 13
9 14
9 15
*/