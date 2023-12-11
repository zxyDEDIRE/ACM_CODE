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
const int INF=1e9+7;
const int maxn=1e6+100;
int sum[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i&& (i&1))sum[i]=sum[i-1]+(p[i]-p[i-1]);
		else sum[i]=sum[i-1];
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l,r,ans=0;
		cin>>l>>r;
		int fl=lower_bound(p+1,p+1+n,l)-p;
		int fr=upper_bound(p+1,p+1+n,r)-p-1;
		// cout<<fl<<" "<<fr<<endl;
		// cout<<p[fl]<<" "<<p[fr]<<endl;
		// cout<<sum[fl]<<" "<<sum[fr]<<endl;
		if(fr>=fl)
			ans+=sum[fr]-sum[fl];
		if(fl>fr&&(fl&1))ans+=r-l;
		if(fl<=fr&&l<p[fl]&&fl>1&&(fl&1))
			ans+=p[fl]-l;
		if(fl<=fr&&r>p[fr]&&(fr%2==0))
			ans+=r-p[fr];
		cout<<ans<<endl;
	}
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
/*
7
0 240 720 1320 1440 1800 2160
1
480 500
*/