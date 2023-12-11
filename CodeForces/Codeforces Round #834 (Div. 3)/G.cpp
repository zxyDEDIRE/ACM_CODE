/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Seg{
	int l,r,val;
}t[maxn<<2];
bitset<maxn>vis;
int ans[maxn];
int p[maxn];
int s[maxn];
int n;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void update(int rt,int k,int c)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(k<=mid)update(rt<<1,k,c);
	else update(rt<<1|1,k,c);
	t[rt].val=(t[rt<<1].val|t[rt<<1|1].val);
}
int query(int rt,int k)
{
	if(t[rt].l==t[rt].r)
		return t[rt].l;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(t[rt<<1|1].val)return query(rt<<1|1,k);
	else if(t[rt<<1].val)return query(rt<<1,k);
	return 0;
}
void solve()
{
	cin>>n;
	vis.reset();
	int flag=0;
	for(int i=1;i<=n/2;i++)
	{
		cin>>p[i];
		if(vis[p[i]]){
			flag=1;
		}
		vis[p[i]]=1;
		s[p[i]]=i;
	}
	if(flag){
		cout<<-1<<endl;
		return ;
	}
	build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		if(vis[i])update(1,s[i],1);
		else
		{
			int x=query(1,i);
			if(x==0){
				cout<<-1<<endl;
				return ;
			}
			ans[x]=i;
			update(1,x,0);
		}
	}
	for(int i=1;i<=n/2;i++)
		cout<<ans[i]<<" "<<p[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
1 2 3 4 5 6 7 8 



 8 2 4

*/