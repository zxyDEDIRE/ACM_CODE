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
char p[maxn];
char a[maxn];
ll m;
int n;
void solve()
{
	scanf("%d %lld %s",&n,&m,p+1);
	if(m==0)
	{
		printf("%s\n",p+1);
		return ;
	}
	if(n==1)
	{
		if(m&1)p[1]^=1;
		printf("%s\n",p+1);
		return ;
	}
	int flag=0;
	for(int i=0;i<=n;i++)
		a[i]=p[i];
	a[n+1]='\0';

	int pre=-1;
	for(int i=1;i<=n;i++)
	{
		if(p[i]=='1')
		{
			if(pre!=-1 && m)
			{
				m--;
				for(int j=pre;j<i;j++)
					a[j]='1';
			}
			pre=-1;
		}
		else
		{
			if(p[i]=='0' && pre==-1)pre=i;
		}
		
		if(p[i]=='1'&&p[i-1]=='0')flag=1;
		if(p[i]=='0'&&p[i-1]=='1')flag=1;
	}
	if(pre!=-1 && m)
	{
		m--;
		for(int j=pre;j<=n;j++)
			a[j]='1';
	}
	if(!flag&&m==1)a[n]='0';
	printf("%s\n",a+1);
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
/*
01
00

*/