/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define pp(x) array<int,x>
// using ull=unsigned long long;
// using ll=long long;
// using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n;
	cin>>n;
	int s=1000;
	int m=60*s;
	int h=60*m;
	int day=24*h;
	n%=day;

	int a=n/h;n%=h;
	int b=n/m;n%=m;
	int c=n/s;
	if(a<=9)cout<<"0"<<a;
	else cout<<a;
	if(b<=9)cout<<":0"<<b;
	else cout<<":"<<b;
	if(c<=9)cout<<":0"<<c;
	else cout<<":"<<c;
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}