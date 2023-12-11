#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
struct Seg{int l,r,id,val;}t[maxn<<2];
priority_queue<pair<int,int>>q[11];
vector<int>v[11];
bitset<maxn>vis;
int top[11];
int p[maxn];
string str;
int n,d;
void pushup(int rt){
	if(t[rt<<1].val>=t[rt<<1|1].val)
		t[rt].val=t[rt<<1].val,t[rt].id=t[rt<<1].id;
	else
		t[rt].val=t[rt<<1|1].val,t[rt].id=t[rt<<1|1].id;
}
void build(int rt,int l,int r){t[rt]={l,r,l,0};if(l==r){t[rt].val = p[l];return ;}int mid = (l + r) >> 1;build(rt << 1, l, mid);build(rt << 1 | 1, mid + 1, r);pushup(rt);}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)return t[rt].id;
	int mid=(t[rt].l==t[rt].r)>>1;
	int ans=0;
	if(l<=mid){
		int x=query(rt<<1,l,r);
		if(p[x]>p[ans])ans=x;
	}
	if(r>mid){
		int x=query(rt<<1|1,l,r);
		if(p[x]>p[ans])ans=x;
	}
	return ans;
}
void update(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val=0;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid) update(rt<<1,l);
	else update(rt<<1|1,l);
	pushup(rt);
}
void solve()
{
	n=str.size();
	for(int i=1;i<=n;i++)
		p[i]=str[i-1]-'0';
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			pair<int,int>now =q[p[i]].top();
			
		}
		else
		{
			int ans=query(1,i,i+d);
			if(ans==i)continue;
			vis[ans]=1;
			v[p[ans]].push_back(i);
			q[p[ans]].push({p[i],i});
		}
	}
}
signed main()
{
	while(cin>>str>>d)
		solve();
}
