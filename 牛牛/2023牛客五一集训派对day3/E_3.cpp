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
const int maxn=1e3+100;
struct node{
	struct K{
		int x,id;
	}p[maxn];
	int a[maxn];
	int b[maxn];
	bitset<maxn>vis;
	int n,ans=INF;
	void dfs(int x,int now)
	{
		if(x>n){
			if(now<=ans)
			{
				ans=min(ans,now);
				cout<<now<<endl;
				for(int i=1;i<=n;i++)
					cout<<a[i]<<" ";cout<<endl;
				for(int i=1;i<=n;i++)
					cout<<b[i]<<" ";cout<<endl;
				cout<<endl;
			}
			return ;
		}
		if(now>ans)return ;
		if(vis[x])dfs(x+1,now);
		// cout<<x<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i==a[x])continue;
			if(vis[i])continue;
			if(i==x)continue;
			b[x]=i;
			b[i]=x;
			vis[x]=vis[i]=1;
			dfs(x+1,now+abs(p[x].x-p[i].x));
			vis[x]=vis[i]=0;
		}
	}
	int get(int N,int *A)
	{
		n=N;
		for(int i=1;i<=n;i++)
		{
			a[i]=b[i]=i;
			p[i].x=A[i],p[i].id=i;
		}
		sort(p+1,p+1+n,[&](K a,K b){
			if(a.x!=b.x)return a.x<b.x;
			return a.id<b.id;
		});
		for(int i=1;i<=n;i+=2)
		{
			int x=p[i].id;
			int y=p[i+1].id;
			a[x]=y;
			a[y]=x;
		}
		sort(p+1,p+1+n,[&](K a,K b){
			return a.id<b.id;
		});
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=abs(p[i].x-p[a[i]].x);
		sum/=2;
		dfs(1,0);
		ans+=sum;
		// cout<<ans<<endl;
		return ans;
	}
}A;
void solve()
{
	int n;
	int p[112];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<A.get(n,p)<<endl;
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
6
1 2 3 4 5 6
*/