/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int l,r,val,fl;
}t[maxn<<2];
bitset<maxn>vis;
int p[maxn];
int n,k;
void pushup(int rt)
{
	if(t[rt<<1].val>=t[rt<<1|1].val)
	{
		t[rt].val=t[rt<<1].val;
		t[rt].fl=t[rt<<1].fl;
	}
	else
	{
		t[rt].val=t[rt<<1|1].val;
		t[rt].fl=t[rt<<1|1].fl;
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	// t[rt].val=t[rt].fl=0;
	if(l==r)
	{
		cin>>p[l];
		t[rt].val=p[l];
		t[rt].fl=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		pii a;
		a.first=t[rt].val;
		a.second=t[rt].fl;
		return a;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pii ans;
	ans.first=ans.second=0;
	if(l<=mid)
	{
		pii a=query(rt<<1,l,r);
		if(a.first>ans.first)ans=a;
	}
	if(r>mid)
	{
		pii a=query(rt<<1|1,l,r);
		if(a.first>ans.first)ans=a;
	}
	return ans;
}
void solve()
{
	cin>>n>>k;
	vis.reset();
	build(1,1,n);
	vectorXint>ans;
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(k)
		{
			pii ans=query(1,i,min(n,i+k));
			int x=ans.second;
			for(int j=i;j<x;j++)
			{
				k--;
				vis[j]=1;
				q.push(p[j]);
			}
		}
		if(!vis[i])ans.push_back(p[i]);
	}
	vector<int>t;
	for(auto i:ans)
	{
		while(q.size()&&q.top()>i)
		{
			t.push_back(q.top());
			q.pop();
		}
		t.push_back(i);
	}
	while(!q.empty())
	{
		t.push_back(q.top());
		q.pop();
	}
	for(int i=0;i<n;i++)
	{
		cout<<t[i];
		if(i!=n-1)cout<<" ";
	}
	cout<<endl;

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

2
8 4
3 9 4 8 7 6 1 5
8 4
3 9 3 8 7 6 1 5

9 8 7 6 5 4 1 3
9 8 7 6 5 3 3 1


1
5 2
5 2 4 3 1


2
9 1 1
9 3 3
*/