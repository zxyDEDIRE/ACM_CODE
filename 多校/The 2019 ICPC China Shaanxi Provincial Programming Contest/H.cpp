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
vector<int>a[maxn];
int prime[maxn];
int ma_p[maxn];
bitset<maxn>vis;
int n;
void init(int N)
{
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void f(int N)
{
	for(int i=1;i<=N;i++)
	{
		int x=i;
		int ans=0;
		for(int j=1;j<=prime[0];j++)
		{
			if(x==1)break;
			if(x%prime[j]==0)
			{
				// a[prime[j]].push_back(i);
				ans=prime[j];
				while(x%prime[j]==0)
					x/=prime[j];
			}
		}
		// a[ans].push_back(i);
		ma_p[i]=ans;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i].clear();
	for(int i=1;i<=n;i++)
		a[ma_p[i]].push_back(i);

	vector<pii>ans;
	for(int i=n;i>=2;i--)
	{
		if(a[i].size()<2)continue;
		int x=-1,flag=-1;
		if(a[i].size()&1)flag=-2;
		for(auto y:a[i])
		{
			if(y%2==0&&flag==-2&&i!=2)flag=y,a[2].push_back(y);
			else if(x==-1)x=y;
			else ans.push_back({x,y}),x=-1;
		}
	}
	cout<<ans.size()<<" ";
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init(1e5);
	f(1e5);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}