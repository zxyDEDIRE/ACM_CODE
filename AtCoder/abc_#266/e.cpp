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
void solve()
{
	int n;
	cin>>n;

	double ans=3.5;
	for(int i=2;i<=n;i++)
	{
		double res=0;
		for(int j=1;j<=6;j++)
		{
			if(j>ans)res+=j;
			else res+=ans;
		}
		ans=res/6;
	}
	printf("%.6lf",ans);
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}