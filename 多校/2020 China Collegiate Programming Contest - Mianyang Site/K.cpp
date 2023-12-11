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
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll f(ll x)
{
	if(x&1)
	{
		//x x+2 x+3
		if(gcd(x+3,x)!=1)return -1;
		else if(gcd(x+2,x)!=1)return -1;
		else return 3*x+5;
	}
	else
	{
		//x x+1 x+3
		if(gcd(x+3,x)!=1)return -1;
		else if(gcd(x+3,x+1)!=1)return -1;
		else return x*3+4;
	}
}
void solve()
{
	ll x;
	cin>>x;
	if(x&1)cout<<1<<endl;
	else if(x==6)cout<<-1<<endl;
	else if(x%4==0)cout<<2<<endl;
	else if(x%3==0)cout<<2<<endl;
	else
	{
		if(f(x/3-1)==x)cout<<3<<endl;
		else if(f(x/3)==x)cout<<3<<endl;
		else cout<<4<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
Case #1: 1
Case #2: -1
Case #3: 1
Case #4: 3
Case #1: 1
Case #2: -1
Case #3: 1
Case #4: 3

*/