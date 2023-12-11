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
ll a,b,c,d;
void solve()
{
	cin>>a>>b>>c>>d;
	if(a==0){
		cout<<1<<endl;
		return ;
	}
	ll ans=a;
	ans+=min(b,c)*2;
	ans+=min(a+1,max(b,c)-min(b,c)+d);
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
2 5 10 6
2 2*2
0 4*2
4 0*4
0 4*4
1 3*2


a*2
b*5
c*6
d*2

2 2 * 2
2 2 *5
1 3 *1
*2

*/