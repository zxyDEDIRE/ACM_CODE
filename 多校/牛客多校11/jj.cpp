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
int a[4],x,n;
void solve()
{
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		cin>>p[i];
	p[0]=p[n];
	for(int i=1;i<=n;i++)
	{
		x=(p[i]-p[i-1]+3)%3;
		a[x]++;
	}
	cout<<(a[1]>=a[2]?"Yes":"No")<<endl;
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