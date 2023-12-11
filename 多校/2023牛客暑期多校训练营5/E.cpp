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
const int maxn=2e3+100;
pp(3) p[maxn];
int a[maxn];
int cnt[maxn];
int n,m;
void dfs(int l,int r,int op=-1)
{
	vector<pii>now;
	int sum=0;
	int x=-1;
	for(int i=1;i<=m;i++)
	{
		if(p[i][0]<l)continue;
		if(p[i][1]>r)break;
		if(p[i][0]==l&&p[i][1]==r)continue;
		if(x==-1)x=i;
		else if(p[x][0]<=p[i][0]&&p[x][1]>=p[i][1])continue;
		else
		{
			dfs(p[x][0],p[x][1],p[x][2]);
			now.push_back({p[x][0],p[x][1]});
			sum+=p[x][2];
			x=i;
		}
	}
	if(x!=-1)
	{
		dfs(p[x][0],p[x][1],p[x][2]);
		now.push_back({p[x][0],p[x][1]});
		sum+=p[x][2];
	}
	int flag=0;
	if(op==0&&(sum%2==1))flag=1;
	if(op==1&&(sum%2==0))flag=1;
	if(!flag)return ;
	for(int i=l;i<=r;i++)
		cnt[i]=0;
	for(int i=0;i<now.size();i++)
	{
		auto [l,r]=now[i];
		for(int k=l;k<=r;k++)
			cnt[k]+=i+1;
	}
	l=max(l,1);
	for(int i=l+1;i<=r;i++)
	{
		if(cnt[i]==0||cnt[i-1]==0)
		{
			swap(a[i],a[i-1]);
			return ;
		}
		if(cnt[i]-cnt[i-1]==1)
		{
			// cout<<"SDf"<<endl;
			swap(a[i],a[i-1]);
			return ;
		}
	}
	cout<<-1<<endl;
	exit(0);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=m;i++)
	{
		auto &[x,y,w]=p[i];
		cin>>x>>y>>w;
	}
	sort(p+1,p+1+m,[&](pp(3)a,pp(3)b){
		if(a[0]!=b[0])return a[0]<b[0];
		return a[1]>b[1];
	});

	dfs(0,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";cout<<endl;
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
4 3
1 2 0
3 4 0
1 4 1


4 4
1 2 0
3 4 0
2 3 1
1 4 1
*/