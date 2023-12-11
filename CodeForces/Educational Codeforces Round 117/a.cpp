/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll x,y;
	cin>>x>>y;
	if((x+y)&1){
		cout<<"-1 -1"<<endl;
		return ;
	}
	ll t=(x+y)/2;
	if(x>=t)cout<<x-t<<" "<<y<<endl;
	else cout<<x<<" "<<y-t<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}