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
struct node{
	int l,r,val;
}t[maxn<<2];
int p[maxn];
int n,ans;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void query(int rt,int k)
{
	// cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(ans!=-1)return ;
	if(t[rt].l==t[rt].r)
	{
		ans=t[rt].l;
		return ;
	}
	if(t[rt<<1|1].val<k)
		query(rt<<1|1,k);
	if(t[rt<<1].val<k)
		query(rt<<1,k);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		ans=-1;
		query(1,p[i]);
		if(ans==-1||ans<i)cout<<-1<<" ";
		else cout<<ans-i-1<<" ";
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}