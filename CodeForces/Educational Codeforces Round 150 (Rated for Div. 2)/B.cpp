/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int n;
void solve()
{
	cin>>n;
	int flag=0;
	int pre=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(flag==0)
		{
			if(p[i]>=pre)pre=p[i],cout<<1;
			else if(p[i]<=p[1])flag=1,pre=p[i],cout<<1;
			else cout<<0;
		}
		else
		{
			if(p[i]>=pre&&p[i]<=p[1])cout<<1,pre=p[i];
			else cout<<0;
		}
	}
	cout<<"\n";
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
9
3 7 7 9 2 4 6 3 4
1 1 1 1 1 0 0 1 0
*/
