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
inline void write(__int128 x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{
	int n;
	cin>>n;
	__int128 N=n;
	for(int i=3;i<=60;i++)
	{
		int l=2;
		int r=1e9+10;
		int ans=l;

		auto check=[&](int mid)->int{
			__int128 sum=0,t=1;
			for(int j=1;j<=i;j++)
			{
				sum+=t;
				if(t>N)return 2;
				t*=mid;
				if(sum>N)return 2;
			}
			if(sum==N)return 1;
			return 0;
		};

		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check(mid))ans=mid,r=mid;
			else l=mid;
		}
		// cout<<ans<<endl;
		// cout<<check(ans)<<endl;
		while(ans>2&&check(ans-1))ans--;
		if(check(ans)==1){
			cout<<"YES"<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
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
/*
1-q^n
*/