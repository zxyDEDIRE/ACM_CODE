/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
bool vis[maxn];
int p_a[maxn];
int p_b[maxn];
int a[maxn];
int b[maxn];
int n;
void f(int l,int r);
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p_a[a[i]]=i;
	for(int i=1;i<=n;i++)
		cin>>b[i],p_b[b[i]]=i;
	int ans=n*(n+1)/2;
	int l=min(p_a[1],p_b[1]);
	int r=max(p_a[1],p_b[1]);
	ans=ans-(r-1)-(l-1)*(r-l-1)-(n-l)-(r-l-1)*(n-r);
	for(int i=l;i<=r;i++)
		vis[a[i]]=1,vis[b[i]]=1;
	// cout<<"ANS "<<ans<<endl;
	for(int x=2;x<=n;x++)
	{
		int L=min(p_a[x],p_b[x]);
		int R=max(p_a[x],p_b[x]);
		if(L>=l&&R<=r)continue;
		if(R<l)
		{
			int x=R-L;
			int y=n-r+1;
			ans-=x*y;
		}
		else if(L>r)
		{
			int x=l;
			int y=R-L;
			ans-=x*y;
		}
		else if(L>=l&&L<=r)
		{
			int x=l;
			int y=R-r;
			ans-=x*y;
		}
		else if(R>=l&&R<=r)
		{
			int x=l-L;
			int y=n-r+1;
			ans-=x*y;
		}
		// cout<<x<<" ";
		// cout<<ans<<endl;
		while(l>L)
			l--,vis[a[l]]=1,vis[b[l]]=1;
		while(r<R)
			r++,vis[a[r]]=1,vis[b[r]]=1;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
7
7 3 6 2 1 5 4
6 7 2 5 3 1 4
28
21
19

3

3 6
3 7
*/