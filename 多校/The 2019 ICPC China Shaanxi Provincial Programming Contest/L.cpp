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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void NO(){cout<<0<<endl;}
void solve()
{
	ll l,r;
	cin>>l>>r;
	string a,b;
	a=to_string(l);
	b=to_string(r);
	if(a.size()!=b.size())return NO();
	for(int i=0;i<(int)a.size()-1;i++){
		if(a[i]!=b[i])return NO();
		if(a[i]=='0'||b[i]=='0')return NO();
	}
	if(a.back()=='0'||b.back()=='0')return NO();
	ll ans=1 ;
	for(int i=l;i<=r;i++)
	{
		ll x=i;
		while(x){
			ans=ans*(x%10)%mod;
			x/=10;
		}
	}
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