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
ll p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	int a=0,b=0;
	p[0]=p[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=2;i<n;i++)
	{
		if(!(i&1))a++;
		if(p[i]>p[i-1]+p[i+1])b++;
	}
	if(k==1)cout<<a<<endl;
	else cout<<b<<endl;

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