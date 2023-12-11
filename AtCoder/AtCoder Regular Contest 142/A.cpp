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
int n,k;
int ans=0;
int f(int n)
{
	int x=0;
	while(n){
		x=x*10+n%10;
		n/=10;
	}
	return x;
}
void solve()
{
	cin>>n>>k;
	if(k%10==0){
		if(k<=n)cout<<1<<endl;
		else cout<<0<<endl;
		return ;
	}
	int x=k;
	int y=f(k);
	if(y<x){
		cout<<0<<endl;
		return ;
	}
	while(x<=n){
		ans++;
		x*=10;
	}
	if(y!=k)
	while(y<=n){
		ans++;
		y*=10;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
12
120
21
210

*/