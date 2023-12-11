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
const int maxn=1e6+2000;
ll F[maxn];
ll R[maxn],T;
ll n,ans;
void solve()
{ 
	cin>>n;
	int S=lower_bound(R+1,R+1+1413,n)-R;
	ans=0;
	if(R[S]>n)S--;
	int r=n-R[S]+1;
	for(int i=S;i>=1;i--)
	{
		int L=R[i];
		int _l=max(1ll,r-(S-i));
		int _r=min(i,r);
		ans+=F[L+_r-1]-F[L+_l-2];
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=1;i<=1e6+1000;i++)
		F[i]=F[i-1]+1ll*i*i;
	ll _x=1,_y=1;
	for(int i=1;;i++)
	{
		if(_x>1e6+1000)break;
		R[++T]=_x-_y+1;
		_y++;
		_x+=_y;
	}
	// cout<<T<<endl;
	// 1413'





	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
58116199242129511
1
4
9
25
36
81
*/