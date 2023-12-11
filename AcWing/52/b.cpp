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
int a[maxn],b[maxn];
int p[maxn];
int n,t;
void solve()
{
	cin>>n;
	t=n;
	a[0]=b[n+1]=n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		a[i]=a[i-1]+1;
		if(p[i]==0)a[i]=0;
	}
	for(int i=n;i>=1;i--)
	{
		b[i]=b[i+1]+1;
		if(p[i]==0)b[i]=0;
	}
	for(int i=1;i<=n;i++)
		cout<<min(a[i],b[i])<<" ";
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}
/*
(d-x)+x=(d-x)*x
d=dx+x*x
*/