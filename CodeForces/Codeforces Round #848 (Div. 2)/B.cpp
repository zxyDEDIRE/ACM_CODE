/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int maxn=1e6+100;
int t[maxn];
int p[maxn];
int a[maxn];
int n,m,d;
void swap(int x,int y);
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
		cin>>p[i],t[p[i]]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	int ans=INF;
	for(int i=1;i<m;i++)
	{
		int x=t[a[i]];
		int y=t[a[i+1]];
		int len=y-x;
		if(len>=0&&len<=d)
		{
			int xx=d+1-len;
			int yy=len;
			if(d+2>n||yy<xx)
				ans=min(ans,yy);
			else ans=min(ans,xx);
		}
		else ans=min(ans,0);
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
1234
21
*/