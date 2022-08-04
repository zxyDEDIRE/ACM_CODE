/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int N=300007;
int a[N];
namespace seg_tree
{
	struct node
	{
		int l,r;
		int maxn;
	}t[N<<2];

	void pushup(int k)
	{
		t[k].maxn=max(t[k<<1].maxn,t[k<<1|1].maxn);
	}

	void build(int k,int l,int r)
	{
		t[k].l=l;
		t[k].r=r;
		if(l==r)
		{
			t[k].maxn=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
		return ;
	}

	int query(int k,int l,int r)
	{
		if(l<=t[k].l&&t[k].r<=r)
		{
			return t[k].maxn;
		}
		int ans=0;
		int mid=(t[k].l+t[k].r)>>1;
		if(l<=mid)ans=max(ans,query(k<<1,l,r));
		if(r>mid)ans=max(ans,query(k<<1|1,l,r));
		return ans;
	}
} 
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>v,G;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	seg_tree::build(1,1,n);
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=seg_tree::query(1,i,min(i+k,n)))
		{
			G.push_back(a[i]);
		}
		else 
		{
			k--;
			q.push(a[i]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(q.size()==0)
		{
			a[i]=G[cnt++];
			continue;
		}
		if(cnt==G.size())
		{
			a[i]=q.top();
			q.pop();
			continue;
		}
		if(G[cnt]>=q.top())
		{
			a[i]=G[cnt++];
		}
		else 
		{
			a[i]=q.top();
			q.pop();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)cout<<a[i];
		else cout<<" "<<a[i];
	}
	cout<<'\n';
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}