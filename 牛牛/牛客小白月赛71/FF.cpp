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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n;
int mull(int a,int b){int qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int f(int x){
	if(x==1)return 1;
	else return mull(x+1,ksm(2,x-2));
}
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		sum+=p[i];
		int x=f(i);
		int ans=mull(x,sum);
		// cout<<sum<<" "<<f(i)<<" "<<sum*f(i)<<" "<<ksm(2,i)<<endl;
		// ans=(ans*ksm(ksm(2,i),mod-2))%mod;
		ans=mull(ans,ksm(ksm(2,i),mod-2));
		cout<<ans<<" ";
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