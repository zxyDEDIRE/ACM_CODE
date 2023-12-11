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
ll aa,bb;
void solve()
{
	cin>>aa>>bb;
	int mi=10000;
	for(int i=0;i<=100;i++)
	{
		int a=aa;
		int b=bb;
		int cnt=1;
		b+=i;
		cnt+=i;
		if(b==1)continue;
		while(a>b)
		{
			a/=b;
			cnt++;
		}
		if(a==b)cnt++;
		mi=min(mi,cnt);
	}
	cout<<mi<<endl;
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