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
ll n;
void solve()
{
	cin>>n;
	for(int len=30;len>=1;len--)
	{
		cout<<len<<endl;
		auto check=[&](int mid)->bool{
			for(int i=1;i<=len;i++)
			{
				if(n<mid||n%mid!=0)return 0;
				mid++;
			}
			return 1;
		};

		int l=1,r=n,ans=-1;
		while(l<r-1)
		{
			int mid=(l+r)/2;
			if(check(mid))ans=mid,r=mid;
			else l=mid;
		}
		while(ans>1&&check(ans-1))ans--;
		cout<<"ANS "<<ans<<endl;
		if(ans==-1)continue;
		cout<<len<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
x x+len-1

(x+x+len-1)*len/2;
(2*x+len-1)*len/2
*/