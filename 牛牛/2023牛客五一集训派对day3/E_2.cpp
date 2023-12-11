#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
#define int long long
#define ll long long
const int N = 2e5 + 10;
const int maxn=100;


ll pre[N], suf[N];
int a[maxn];

int solve(int n,int *b){
	for(int i=1;i<=n;i++)
		a[i]=b[i];
	sort(a + 1, a + 1 + n);

	ll ans = 0;
	for(int i = 1; i <= n; i += 2){
		ans += a[i + 1] - a[i];
	}
	if(n % 4 == 0){
		for(int i = 1; i <= n; i += 4){
			ans += a[i + 2] - a[i];
			ans += a[i + 3] - a[i + 1];
		}
	}
	else{
        for(int i = 0; i <= n + 1; i ++){
            pre[i] = suf[i] = 0;
        }
        for(int i = n; i > 6; i -= 4){
            suf[i - 3] = suf[i + 1] + 1LL * (a[i] - a[i - 2]) + 1LL * (a[i - 1] - a[i - 3]);
        }
        for(int i = 4; i <= n; i += 4){
            pre[i] = pre[i - 4] + 1LL * (a[i] - a[i - 2]) + 1LL * (a[i - 1] - a[i - 3]);
        }
        ll res = INF;
        for(int i = 0; i + 6 <= n; i += 4){
            ll sum = 1LL * (a[i + 3] - a[i + 1]) + 1LL * (a[i + 6] - a[i + 4]) + 1LL * (a[i + 5] - a[i + 2]);
            res = min(res, pre[i] + suf[i + 7] + sum);
        }
        ans += res;
    }
	return ans;
}
int F[maxn];
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
				// cout<<now<<endl;
				// for(int i=1;i<=n;i++)
				// 	cout<<a[i]<<" ";cout<<endl;
				// for(int i=1;i<=n;i++)
				// 	cout<<b[i]<<" ";cout<<endl;
				// cout<<endl;
			}
			return ;
		}
		if(now>=ans)return ;
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
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n=8;
	srand(time(0));
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			F[i]=abs(rand()%15);
		}
		ll ans_1=solve(n,F);
		ll ans_2=A.get(n,F);
		if(ans_1!=ans_2)
		{

			cout<<"yangli :\n";
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
				cout<<F[i]<<" ";
			cout<<endl;
			cout<<ans_1<<" "<<ans_2<<endl;
			return 0;
		}
	}
	
	return 0;
}
/*
8
1 2 3 4 5 6 7 8 // 12
*/