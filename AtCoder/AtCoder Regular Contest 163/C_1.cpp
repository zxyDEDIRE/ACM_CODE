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
void f(int n,int fl=1)
{
	for(int i=1;i<n;i++)
		cout<<1ll*fl*i*(i+1)<<" ";
	cout<<1ll*fl*n<<endl;
}
void solve()
{
	int n;
	cin>>n;
	if(n==2){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
	if(n==1){
		cout<<"1"<<endl;
		return ;
	}
	int flag=0;
	for(int i=1;i<500;i++)
		if(n==i*(i+1))flag=1;
	if(flag)
	{
		cout<<2<<" ";
		f(n-1,2);
	}
	else f(n);

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
2 3

*/