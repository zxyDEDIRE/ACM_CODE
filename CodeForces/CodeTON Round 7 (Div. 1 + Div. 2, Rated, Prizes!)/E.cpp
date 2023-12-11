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
int n;
void solve()
{
	cin>>n;
	vector<int>v,u,q;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==i)ans[p[i]]=0,update(1,i);
		else v.push_back(p[i]);
	}
	int now=0;
	while(v.size())
	{
		int mi=n;
		int len=v.size();
		for(int i=0;i<len;i++)
		{
			int x=v[i];
			int y=query(1,x);
			int fl=(y-(i+1)+len)%len;
			mi=min(mi,fl);
			// cout<<x<<" "<<y<<" "<<fl<<endl;
		}
		// for(auto i:v)
		// 	cout<<i<<" ";cout<<endl;
		now+=mi;
		u.clear();
		for(int i=len-mi;i<len;i++)
			u.push_back(v[i]);
		for(int i=0;i<len-mi;i++)
			u.push_back(v[i]);
		v.clear();
		q.clear();
		for(int i=0;i<len;i++)
		{
			int x=u[i];
			if(i+1==query(1,x))
			{
				ans[p[x]]=now;
				q.push_back(x);
			}
			else v.push_back(x);
		}
		for(auto i:q)
			update(1,i);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[p[i]]<<" ";
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