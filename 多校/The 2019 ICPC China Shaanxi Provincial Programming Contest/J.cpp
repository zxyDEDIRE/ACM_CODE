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
pii p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	int ans=0;
	for(int j=30;j>=0;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(p[i].second &(1<<j))cnt++;
		if(cnt==n)
		{
			ans|=(1<<j);
			for(int i=1;i<=n;i++)
				if(!(p[i].first&(1<<j)))
					p[i].first=0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(p[i].second&(1<<j))
				{
					if(!(p[i].first&(1<<j)))
					{
						p[i].second|=((1<<j)-1);
					}	
				}
			}
		}
		// for(int i=1;i<=n;i++)
		// 	cout<<p[i].second<<" ";cout<<endl;
	}
	cout<<ans<<endl;
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
8421

*/