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
	int x,y,z;
}p[111];
int a[111];
int n,m;
int f(int x,int y,int z){
	int ans=x;
	ans=(int)max(x*0.3,x*(1-0.004*y)-z*50);
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y>>p[i].z;
	for(int i=1;i<=n;i++)
		a[i]=i;
	int ans=0;
	do{
		int s=0,now=0;
		for(int i=1;i<=n;i++)
		{
			auto [x,y,z]=p[a[i]];
			if(s+y>m)break;
			now+=f(x,y+s,z);
			s+=y;
		}
		ans=max(ans,now);
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}