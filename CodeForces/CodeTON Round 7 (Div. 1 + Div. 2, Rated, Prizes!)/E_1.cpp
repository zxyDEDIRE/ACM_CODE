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
struct Seg{
	int l,r,val;
}t[maxn<<2];
void pushup(int rt){t[rt].val=t[rt<<1].val+t[rt<<1|1].val;};
void build(int rt,int l,int r){
	t[rt]={l,r,1};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val=0;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	pushup(rt);
}
int query(int rt,int r){
	if(t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	ans+=query(rt<<1,r);
	if(r>mid)ans+=query(rt<<1|1,r);
	return ans;
}
int ans[maxn];
int p[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	vector<int>v,u,q;
	build(1,1,n);
	int num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==i)ans[p[i]]=0,update(1,i),num++;

	}
	int mi=INF;
	int now=0;
	int len=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(p[i]!=i){
			v.push_back(p[i]);
			a[p[i]]=query(1,p[i]);
			b[p[i]]=(a[p[i]]-(int)v.size()+(n-num))%(n-num);
			mi=min(mi,b[p[i]]);
		}

	for(auto i:v)
		cout<<i<<" "<<b[i]<<endl;
	exit(0);
	while(v.size())
	{
		now+=mi;
		u.clear();
		len=v.size();
		// for(auto i:v)
		// 	cout<<i<<" ";cout<<endl;
		// cout<<mi<<endl;
		for(int i=len-mi;i<len;i++)
		{
			int x=v[i];
			if(b[x]==mi)update(1,x),ans[x]=now;
			else u.push_back(x);
		}
		for(int i=0;i<len-mi;i++)
		{
			int x=v[i];
			if(b[x]==mi)update(1,x),ans[x]=now;
			else u.push_back(x);
		}
		// for(auto i:u)
		// 	cout<<i<<" ";
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<ans[p[i]]<<" ";cout<<endl;
		// cout<<endl;
		mi=INF;
		cnt=0;
		len=u.size();
		for(int i=0;i<len;i++)
		{
			int x=u[i];
			a[x]=query(1,x);
			b[x]=(a[x]-(i+1)+len)%len;
			if(b[x]<mi)
			{
				mi=b[x];
				cnt=1;
			}
			else if(b[x]==mi)
				cnt++;
		}
		swap(u,v);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2 1 4 5 3
3 2 1 4 5


6
6 1 2 3 4 5
*/