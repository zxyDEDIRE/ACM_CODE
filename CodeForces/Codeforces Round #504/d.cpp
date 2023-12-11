/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int l,r,val;
}t[maxn<<2];
vector<int>v[maxn];
int p[maxn];
int n,k;
void build(int rt,int l,int r)
{
	
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].val=p[l];
		if(t[rt].val==0)t[rt].val=INT_MAX;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
	
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INT_MAX;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void dfs(int rt,int l,int r)
{
	cout<<"("<<endl;
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return ;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)dfs(rt<<1,l,r);
	if(r>mid)dfs(rt<<1,l,r);
}
void solve()
{
	cin>>n>>k;
	int flag=0;
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		v[p[i]].push_back(i);
		if(p[i]>0)flag=1;
		if(p[i]==k)fl=1;
	}
	build(1,1,n);
	for(int i=1;i<=k;i++)
	{
		if(v[i].size()>=2)
		{
			int s=v[i][0];
			int t=v[i].back();
			int mi=query(1,s,t);
			if(mi<i){
				cout<<"NO"<<endl;
				return ;
			}
		}
	}
	cout<<"YES"<<endl;
	if(flag==0)
	{
		for(int i=1;i<=n;i++)
			cout<<k<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			if(fl==0)p[i]=k,fl=1;
			else
			{
				if(i>1&&p[i-1]!=0)p[i]=p[i-1];
				else if(i<n&&p[i+1]!=0)p[i]=p[i+1];
			}
			
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(p[i]==0)
		{
			if(fl==0)p[i]=k,fl=1;
			else
			{
				if(i>1&&p[i-1]!=0)p[i]=p[i-1];
				else if(i<n&&p[i+1]!=0)p[i]=p[i+1];
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}