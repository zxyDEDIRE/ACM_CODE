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
int a[maxn];
int b[maxn];
int n;
int f(int x){
	return x*(x+1)/2;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		b[x]=i;
	}
	int ans=0;
	int l=n,r=1;
	for(int now=1;now<=n;now++)
	{
		int x=a[now];
		int y=b[now];
		if(x>y)swap(x,y);
		if(now==1)
		{
			if(x==y)
				ans=f(x-1)+f(n-y);
			else
				ans=f(x-1)+f(n-y)+f(y-x-1);
			l=x,r=y;
		}
		else
		{
			if(x>r)
				ans+=(x-r)*l;
			else if(y<l)
				ans+=(l-y)*(n-r+1);
			else if(x<l&&y>r)
			{
				ans+=(l-x)*(y-r);
			}
			l=min({l,x,y});
			r=max({r,x,y});
		}
		// cout<<"now "<<now<<"/ ans "<<ans<<endl;
	}
	cout<<ans+1<<endl;
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
1 2 3 4 5 6 7
7 3 6 4 1 5 2
6 7 2 5 3 1 4
5 6
4 6


*/