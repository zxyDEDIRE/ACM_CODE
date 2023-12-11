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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
bitset<maxn>vis,p;
char s[maxn];
int n,m;
void solve()
{
	cin>>n>>s+1;
	int ans=0;
	m=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='2'||s[i]=='3')ans++;
		else p[++m]=s[i]-'0';
		vis[i]=0;
	}
	for(int i=m,r=m-1;i>=1;i--)
	{
		if(vis[i])continue;
		r=min(r,i-1);
		while(r>0&&p[r]!=1)r--;
		if(r>=1&&p[r]==1)
		{
			ans++;
			vis[r]=1;
			r--;
		}
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
10101010

6
1111103
*/