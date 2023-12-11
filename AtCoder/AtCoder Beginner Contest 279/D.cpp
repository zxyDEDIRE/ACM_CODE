/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a,b;
double f(double x)
{
	return 1.0*x*b+1.0*a/sqrt(1+x);
}
void solve()
{
	cin>>a>>b;
	double mi=a;
	int l=0,r=a;
	double eps=10;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		double fl=f(1.0*mid-eps),fr=f(1.0*mid+eps);
		if(fl>fr)
			l=mid;
		else r=mid;
	}
	double ans=f(l);
	for(int i=l-100;i<=r+100;i++)
		ans=min(ans,f(i));
	printf("%.10f\n",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
i*b+a/sqrt(1+i)=x
8772053214538.5976562500
8830770446115.9316406250
*/