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
int a[maxn],b[maxn];
bool vis[maxn];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],sum+=b[i];
	int cnt=n;
	int ans=0;
	queue<int>q;
	while(cnt)
	{
		if(q.empty())
		{
			int x=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				if(a[i]>sum-b[i])
				{
					if(a[i]>a[x])x=i;
					else if(a[i]==a[x])
					{
						if(b[i]>b[x])x=i;
					}
				}
			}
			if(x)
			{
				vis[x]=1;
				sum-=b[x];
				cnt--;
				ans++;
				q.push(x);
				continue;
			}
		 	for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				if(b[i]>b[x])x=i;
				else if(b[i]==b[x]){
					if(a[i]>a[x])x=i;
				}
			}
			vis[x]=1;
			sum-=b[x];
			cnt--;
			ans++;
			q.push(x);
		}
		else
		{
			int x=q.front();q.pop();
			x=b[x];
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				a[i]-=x;
				if(a[i]<=0){
					vis[i]=1;
					sum-=b[i];
					cnt--;
					q.push(i);
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5
1 1
1 2
3 3
6 4
10 5
*/