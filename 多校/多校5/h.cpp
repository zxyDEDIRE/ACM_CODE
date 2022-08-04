/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define PI acos(-1)
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	double n;
	cin>>n;

	n=1.0*n/2;
	double ans=n*n;
	ans+=1.0*PI*n*n/2;
	//printf("%.6f\n",ans);

	double tot=n*n*3;
	//printf("%.6f\n",tot);
	double res=tot-ans+1.0*PI*n*n;
	printf("%.6f\n",res);


	return 0;
}