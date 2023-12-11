/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1000+7;
int n,x,y;
void solve()
{
	cin>>n>>y;
	vector<char>p(n+1,'0');
	for(int i=1;i<=n;i+=3)
		if(y)p[i]='1',y--;
	for(int i=n;i>=1;i--)
	{
		if(p[i]=='1')continue;
		if(y)p[i]='1',y--;
	}
	int ans=0;
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i];
	// cout<<endl;
	for(int i=1;i+2<=n;i++)
	{
		int a=0,b=0;
		if(p[i]=='1')a++;
		else b++;
		if(p[i+1]=='1')a++;
		else b++;
		if(p[i+2]=='1')a++;
		else b++;
		if(a>b)ans++;
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
1111101001001 5
1111001001011
1001001
*/