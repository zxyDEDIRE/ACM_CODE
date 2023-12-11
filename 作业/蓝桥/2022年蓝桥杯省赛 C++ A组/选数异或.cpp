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
const int maxn=1e6+1e5;
struct Seg{
	int l,r,val;
}t[maxn<<2];
vector<int>v[maxn];
set<pii>q;
int p[maxn];
int w[maxn];
int n,m,x,tot;
void pushup(int rt){
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	
}
void solve()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int now=(p[i]^x);
		v[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int now=(p[i]^x);
		if(!v[now].size())continue;
		int fa=lower_bound(v[now].begin(),v[now].end(),i)-v[now].begin();
		int ans=fa;
		if(ans==v[now].size())ans--;
		if(fa>0)
		{
			if(abs(i-v[now][ans])>abs(i-v[now][fa-1]))
				ans=fa-1;
		}
		if(fa<v[now].size()-1)
		{
			if(abs(i-v[now][ans])>abs(i-v[now][fa+1]))
				ans=fa+1;
		}
		ans=v[now][ans];
		q.insert({min(i,ans),max(i,ans)});
	}
	for(auto [x,y]:q)
		w[y]=x;
	build(1,1,n);
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