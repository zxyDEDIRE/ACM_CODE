/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
void solve()
{
	int a,b;
	cin>>a>>b;
	int A=a*2;
	int B=360*b;
	int x,y;
	cout<<A<<" "<<B<<endl;
	cout<<__gcd(A,B)<<endl;
	exgcd(A,B,x,y);
	cout<<x<<" "<<y<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
45 1

*/