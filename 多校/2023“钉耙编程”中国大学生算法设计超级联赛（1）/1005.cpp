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
const ull mod=212370440130137957ll;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const ull prime=233317;
const ull base=131;
char p[maxn];
char a[maxn];
ull t[maxn];
int n,m;
int Get_Min(char *p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			if(p[(i+k)%n]>p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
ull get_hash(char *s)
{
	ull ans=0;
	for(int i=0;i<strlen(s);i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",p);
		int tmp=Get_Min(p,m);
		for(int i=0;i<m;i++)
			a[i]=p[(i+tmp)%m];
		a[m]='\0';
		t[i]=get_hash(a);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(t[x]==t[y])printf("Yes\n");
		else printf("No\n");
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
	scanf("%d",&__);
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}