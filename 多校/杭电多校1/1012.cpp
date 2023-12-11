/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	ll res=0;
	for(int i=0;i<=n;i++)
		cin>>p[i];
	if(p[0]){
		cout<<"Alice"<<endl;
		return ;
	}
	for(int i=n;i>=1;i--)
	{
		p[i-1]+=p[i]/2;
	}
	if(p[0])cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
int main()
{	
	cout<<(2<<15)*15*15<<endl;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1 1
2 2 2 2
3 3 3 3 3 2 2 1
3 3 1
3 3 2 2 

2 2 2 1
3 3 1 3 3 2 2 2
1 2 2

1 2 3 3 3 3 
*/