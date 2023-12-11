/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	double w;
}p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		double sum=0;
		for(int j=1;j<=k;j++){
			double x;cin>>x;
			sum+=x;
		}
		sum=1.0*sum/k;
		p[i].w=sum;
		p[i].x=i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.w!=b.w)return a.w>b.w;
		return a.x<b.x;
	});
	cout<<p[1].x<<endl<<p[2].x<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}