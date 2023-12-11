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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>p[i];
		if(p[i]&1)a[p[i]/2+1]=i;
		else b[p[i]/2]=i;
	}
	int fl=0;
	int ans=0;
	for(int i=1;i<=n*2;i+=2)
	{
		
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}