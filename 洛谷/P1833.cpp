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
int Th,Tm,Sh,Sm;
int n,m,cnt;
void solve()
{
	scanf("%d:%d",&Sh,&Sm);
	scanf("%d:%d",&Th,&Tm);
	scanf("%d",&n);

	m=(Th-Sh)*60+Tm-Sm;

	for(int i=1;i<=n;i++)
	{
		
	}
}
int main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}