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
int p[maxn];
void init()
{
	for(int i=1;i<=4e3+10;i++)
	{
		int cnt=0;
		for(int j=2;j*j<=i;j++)
			if(i%j==0){
				cnt++;
				if(i/j!=j)cnt++;
			}
		if(i==1)cnt++;
		else cnt+=2;
		if(cnt&1)p[i]=1;
	}
	for(int i=1;i<=4e3+10;i++)
		p[i]+=p[i-1];
}
void solve()
{
	int n;cin>>n;
	cout<<p[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}