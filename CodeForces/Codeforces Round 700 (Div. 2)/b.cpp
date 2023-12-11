/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int x,y;
}p[maxn];
int x,y,n;
void solve()
{
	cin>>x>>y>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x;
	for(int i=1;i<=n;i++)
		cin>>p[i].y;

	int need=0,ma=0;
	for(int i=1;i<=n;i++)
	{
		int t=(p[i].y+x-1)/x;
		ma=max(ma,p[i].x);
		need+=t*p[i].x;
	}
	if(need-ma>=y)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}