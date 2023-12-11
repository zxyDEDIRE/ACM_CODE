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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n,p;
void solve()
{
	cin>>n>>p;
	int ans=0;
	int s=1,t=1;
	for(int i=1;i<=n-2;i++)
		s*=i,s%=p; 
	// if(n%2==0)ans+=(s*n)%p;
	// cout<<ans<<endl;
	for(int i=1;i<=n-3;i++)
		t*=i,t%=p;

	int cnt=0;
	for(int i=2;i<=(n+1)/2;i++)
		for(int j=(n+1)/2+1;j<=(i+(n/2));j++)
			cout<<1<<" "<<i<<" "<<j<<endl,
			cnt++;


	ans=n*cnt*t;
	cout<<ans%p<<endl;

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
1 2 4
1 3 4
1 3 5

2 3 5
2 4 5
2 4 1

3 4 1
3 5 1 
3 5 2

4 5 2
4 1 2
4 1 3

5 1 3
5 2 3
5 2 4
*/