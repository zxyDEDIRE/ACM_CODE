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
int mull(int a,int b)
{
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}
void solve()
{
	int l,r;
	cin>>l>>r;
	int num=1,tmp=1;
	while(1)
	{
		int x=l*tmp*2;
		if(x<=r){
			num++;
			tmp*=2;
		}
		else break;
	}
	// cout<<num<<" "<<tmp<<endl;
	int ans=0;
	int _tmp=tmp/2*3;
	if(_tmp!=0)
	{
		int _r=floor(r/_tmp);
		if(_r>=l)
		ans+=mull(num-1,_r-l+1);
	}
	r=floor(r/tmp);
	ans+=(r-l+1);
	ans%=mod;
	
		// ans+=(num-1)*(_r-l+1);
	cout<<num<<" ";
	cout<<ans%mod<<endl;
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