/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=10+7;
const int maxn=1e6+100;
long double p[maxn];
long double d,h;
int n;
void solve()
{
	scanf("%d%Lf%Lf",&n,&d,&h);
	for(int i=1;i<=n;i++)
		scanf("%Lf",&p[i]);
	sort(p+1,p+1+n,[&](long double a,long double b){return a>b;});
	p[0]=INF;
	long double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=0.5*d*h;
		if(i==1)continue;
		if(p[i-1]-p[i]<h)
		{
			long double len=1.0*p[i-1]-p[i];
			len=h-len;
			long double x=1.0*len*d/h;
			// cout<<len<<" "<<x<<endl;
			ans-=0.5*len*x;
		}
	}
	printf("%.9Lf\n",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
3 3 4
3 3 3
*/