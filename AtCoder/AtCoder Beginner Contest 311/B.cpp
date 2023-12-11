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
string p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int pre=-1;
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
			if(p[j][i]=='x')flag=1;
		if(flag==1)
		{
			if(pre!=-1)ans=max(ans,i-pre);
			pre=-1;
		}
		else
		{
			if(pre==-1)pre=i;
		}
	}
	if(pre!=-1)ans=max(ans,m-pre);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}