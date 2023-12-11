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
char ch[maxn];
int n;
void solve()
{
	scanf("%s",ch+1);
	int ans=0;
	int n=strlen(ch+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]!=ch[i-1])
		{
			ans+=max(0,cnt-1);
			cnt=1;
		}
		else cnt++;
	}
	ans+=max(0,cnt-1);
	printf("%lld\n",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;scanf("%d",&__);
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}