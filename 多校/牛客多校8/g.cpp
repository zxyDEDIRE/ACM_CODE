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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int a[maxn];
int n,m,p,x,A,B,C,X;
void solve()
{
	cin>>n>>m>>p>>x>>A>>B>>C;
	map<int,int>mp;
	int cnt=0,t=0,X=x,fl=0,s;
	x=X;
	t=1;
	for(int i=1;i<=t*2;i++)
	{
		x=(A*x*x+B*x+C)%p;
		a[i]=x;s=i;
		if(!mp[x])mp[x]=i,t=max(t,i);
		else 
		{
			t=min(i,i-mp[x]);
			if(t==i-mp[x])fl=i;
			mp[x]=i;
		}
	}
	for(int i=s;i>=1;i--)
	{
		if(a[i-t]!=a[i])
		{
			fl=i-t;
			break;
		}
	}





}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
9
1
1
2
2
*/