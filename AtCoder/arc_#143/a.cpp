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
ll a,b,c;
void solve()
{
	ll p[10];
	for(int i=1;i<=3;i++)
		cin>>p[i];
	sort(p+1,p+4);

	ll x=p[3]-p[2];
	if(p[1]-x<0)
	{
		cout<<-1<<endl;
		return ;
	}

	ll ans=p[1]-x;
	ans+=p[3]-p[1];
	ans+=x;
	cout<<ans<<endl;

}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 6 8
4 2 4
*/