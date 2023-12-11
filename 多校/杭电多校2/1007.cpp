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
struct node{
	int x,y;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		else return a.y<b.y;
	});
	int cnt=0;
	ll t;
	for(int i=1;i<=n;i++)
	{
		if(i==1)cnt++,t=p[i].y;
		else
		{
			if(t>=p[i].x)
			{
				cnt--;
				break;
			}
			else cnt++,t=p[i].y;
		}
	}
	cout<<cnt<<endl;
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