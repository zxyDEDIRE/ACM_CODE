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
const int maxn=2e5+100;
vector<int>v[maxn];
vector<pp(3)>q;
int cl_ma[maxn][21];
int cr_ma[maxn][21];
int cl_mi[maxn][21];
int cr_mi[maxn][21];
int sum[maxn][21];
int ma[maxn][21];
int mi[maxn][21];
int f[maxn][21];
int dep[maxn];
int a[maxn];
int n,tot;
void MA(int x,int y,int k,int rt)
{
	int l_max=ma[x][k];
	int r_max=ma[y][k];
	int left_max=cl_ma[x][k];
	int right_max=cr_ma[y][k];
	int now=left_max+right_max;
	now=max({now,l_max,r_max});

	ma[rt][k+1]=now;
	sum[rt][k+1]=sum[x][k]+sum[y][k];
	cl_ma[rt][k+1]=max(cl_ma[y][k],sum[y][k]+cl_ma[x][k]);
	cr_ma[rt][k+1]=max(cr_ma[x][k],sum[x][k]+cr_ma[y][k]);
}
void MI(int x,int y,int k,int rt)
{
	int l_min=mi[x][k];
	int r_min=mi[y][k];
	int left_min=cl_mi[x][k];
	int right_min=cr_mi[y][k];
	int now=left_min+right_min;
	now=min({now,l_min,r_min});

	mi[rt][k+1]=now;
	cl_mi[rt][k+1]=min(cl_mi[y][k],sum[y][k]+cl_mi[x][k]);
	cr_mi[rt][k+1]=min(cr_mi[x][k],sum[x][k]+cr_mi[y][k]);
}
void dfs(int x,int fa=0)
{
	f[x][0]=fa;
	sum[x][0]=a[x];
	dep[x]=dep[fa]+1;
	ma[x][0]=max(0ll,a[x]);
	mi[x][0]=min(0ll,a[x]);
	cl_ma[x][0]=max(0ll,a[x]);
	cr_ma[x][0]=max(0ll,a[x]);
	cl_mi[x][0]=min(0ll,a[x]);
	cr_mi[x][0]=min(0ll,a[x]);
	for(int i=1;i<=20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		int L=f[x][i-1];
		int R=f[L][i-1];
		// if(!L||!R)continue;
		MA(x,L,i-1,x);
		MI(x,L,i-1,x);
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
	}
}
int LCA_ma(int x,int y)
{
	int _ans=ma[x][0];
	int _sum=sum[x][0];
	int _l=cl_ma[x][0];
	int _r=cr_ma[x][0];
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
		{
			_ans=max(_ans,ma[x][i]);
			_l=max(_l,sum[x][i]+_l);
			_r=max(cr_ma[x][i],sum[x][i]+_r);
			_sum=_sum+sum[x][i];
			_ans=max(_ans,cr_ma[x][i]+_l);
			x=f[x][i];
		}
	if(x==y)return _ans;

	int ans_=ma[y][0];
	int sum_=sum[y][0];
	int l_=cl_ma[y][0];
	int r_=cr_ma[y][0];
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]!=dep[f[y][i]])
		{
			_ans=max(_ans,ma[x][i]);
			_l=max(_l,sum[x][i]+_l);
			_r=max(cr_ma[x][i],sum[x][i]+_r);
			_sum=_sum+sum[x][i];
			_ans=max(_ans,cr_ma[x][i]+_l);

			ans_=max(ans_,ma[y][i]);
			l_=max(l_,sum[y][i]+l_);
			r_=max(cr_ma[y][i],sum[y][i]+r_);
			sum_=sum_+sum[y][i];
			ans_=max(ans_,cr_ma[y][i]+l_);

			x=f[x][i],y=f[y][i];
		}

	for(int i=20;i>=0;i--)
		if(dep[f[y][i]]>=dep[x])
		{
			ans_=max(ans_,ma[y][i]);
			l_=max(l_,sum[y][i]+l_);
			r_=max(cr_ma[y][i],sum[y][i]+r_);
			sum_=sum_+sum[y][i];
			ans_=max(ans_,cr_ma[y][i]+l_);

			y=f[y][i];
		}
	int ans=max({_ans,ans_,_r+r_});
	return ans;
}
int LCA_mi(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int _ans=mi[x][0];
	int _sum=sum[x][0];
	int _l=cl_mi[x][0];
	int _r=cr_mi[x][0];
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
		{
			_ans=min(_ans,mi[x][i]);
			_l=min(_l,sum[x][i]+_l);
			_r=min(cr_mi[x][i],sum[x][i]+_r);
			_sum=_sum+sum[x][i];
			_ans=min(_ans,cr_mi[x][i]+_l);
			x=f[x][i];
		}
	if(x==y)return _ans;

	int ans_=mi[y][0];
	int sum_=sum[y][0];
	int l_=cl_mi[y][0];
	int r_=cr_mi[y][0];
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]!=dep[f[y][i]])
		{
			_ans=min(_ans,mi[x][i]);
			_l=min(_l,sum[x][i]+_l);
			_r=min(cr_mi[x][i],sum[x][i]+_r);
			_sum=_sum+sum[x][i];
			_ans=min(_ans,cr_mi[x][i]+_l);

			ans_=min(ans_,mi[y][i]);
			l_=min(l_,sum[y][i]+l_);
			r_=min(cr_mi[y][i],sum[y][i]+r_);
			sum_=sum_+sum[y][i];
			ans_=min(ans_,cr_mi[y][i]+l_);

			x=f[x][i],y=f[y][i];
		}

	for(int i=20;i>=0;i--)
		if(dep[f[y][i]]>=dep[x])
		{
			ans_=min(ans_,mi[y][i]);
			l_=min(l_,sum[y][i]+l_);
			r_=min(cr_mi[y][i],sum[y][i]+r_);
			sum_=sum_+sum[y][i];
			ans_=min(ans_,cr_mi[y][i]+l_);

			y=f[y][i];
		}
	int ans=min({_ans,ans_,_r+r_});
	return ans;
}
void solve()
{
	cin>>n;
	tot=1;
	a[1]=1;
	q.clear();
	v[1].clear();
	for(int i=1;i<=n;i++)
	{
		char op;
		cin>>op;
		if(op=='+')
		{
			tot++;
			v[tot].clear();
			int fa;
			cin>>fa>>a[tot];
			v[fa].push_back(tot);
			v[tot].push_back(fa);
		}
		else
		{
			int x,y,w;
			cin>>x>>y>>w;
			q.push_back({x,y,w});
		}
	}
	dfs(1);
	for(auto [x,y,w]:q)
	{
		int ans_ma=LCA_ma(x,y);
		int ans_mi=LCA_mi(x,y);
		// cout<<ans_ma<<" "<<ans_mi<<endl;
		if(ans_mi<=w&&w<=ans_ma)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
1
2
+ 1 -1
? 1 1 2
? 1 2 1
*/