/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int n,q;
void solve()
{
	int x,y;
	cin>>x>>y;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(__gcd(i,x)==1&&__gcd(i,y)==1)
		{
			ans++;
		}
	}
	cout<<ans<<endl;

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;
	while(q--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
100 1
12 90
*/