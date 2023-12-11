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
int cnt[maxn];
int n;
void solve()
{
	cin>>n;
	cnt[1]=1;
	for(int x=2;x<=n;x++)
	{
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				if((x/i)!=i)cnt[x]+=2;
				else cnt[x]++;
			}
		}
	}
	// for(int i=1;i<=20;i++)
	// 	cout<<i<<" "<<cnt[i]<<endl;
	int ans=0;
	for(int i=1;i<n;i++)
		ans+=cnt[i]*cnt[n-i];
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
/*
100000

1 2
2 1
2 2
*/