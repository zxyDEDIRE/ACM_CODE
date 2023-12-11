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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int f(int x){return ksm(2,max(0ll,x-1));}
void solve()
{
	int n,ans=0;
	string s;
	cin>>s;
	n=s.size();
	s=" "+s;
	int tmp=0;
	int rmp=0;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'0';
		rmp+=f(i-1);rmp%=mod;
		ans+=((rmp*x)%mod*ksm(10,n-i))%mod;ans%=mod;
		// cout<<i<<" "<<f(i-1)*x*ksm(10,n-i)<<endl;
		tmp*=2;tmp%=mod;
		tmp+=(x*f(i))%mod;tmp%=mod;
		if(i<n)
		{
			ans+=(tmp*ksm(10,n-i-1))%mod;ans%=mod;
			// cout<<tmp<<" "<<n-i-1<<" "<<tmp*ksm(10,n-i-1)<<endl;
		}
	}
	cout<<ans<<endl;
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
1000*1
100*1
10*2
1*4

200*2
20*
*/