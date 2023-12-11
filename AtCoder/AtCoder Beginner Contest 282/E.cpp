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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mod=998244353;
int p[maxn];
int n,m;
int fp(int b,int p)
{
	int r=1;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
void solve()
{
	// cin>>n>>m;
	// for(int i=1;i<=n;i++)
	// 	cin>>p[i];
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