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
	ll x,y;
}p[maxn];
int L[maxn];
int R[maxn];
int n,x,y,a,b;
void solve()
{
	cin>>n>>x>>y>>a>>b;
	int cnt_1=0;
	int cnt_2=0;
	ll ans=0,ma=0;
	for(int i=1;i<=n;i++)
	{
		ll tmp_1,tmp_2,tmp_3;
		cin>>tmp_1>>tmp_2>>tmp_3;
		tmp_1*=x;
		tmp_2*=y;
		tmp_3-=tmp_1+tmp_2;
		if(tmp_3==0)
		{
			cnt_1++;
			cnt_2=0;
			if(cnt_1>=b)ans/=2;
		}
		else
		{
			cnt_1=0;
			cnt_2++;
			ans+=tmp_3;
			if(tmp_3>tmp_1+tmp_2)ans+=ceil(0.5*tmp_3);
			if(cnt_2>=a)ans*=2;
		}
		ma=max(ma,ans);
	}
	cout<<ma<<" "<<ans<<endl;
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