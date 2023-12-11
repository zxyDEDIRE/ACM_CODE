/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
	vector<int>lazy;
}t[2][maxn];
void build(int fl,int rt,int l,int r)
{
	t[fl][rt]={l,r,0,{}};
	if(l==r){
		t[fl][rt].val=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(fl,rt<<1,l,mid);
	build(fl,rt<<1|1,mid+1,r);
}
void pushdown(int fl,int rt)
{
	for(auto i:t[fl][rt].lazy)
	{
		t[fl][rt<<1].val=i-t[fl][rt<<1].val;
		t[fl][rt<<1|1].val=i-t[fl][rt<<1|1].val;
		t[fl][rt<<1].lazy.push_back(i);
		t[fl][rt<<1|1].lazy.push_back(i);
	}
	t[fl][rt].lazy.clear();
}
void update(int fl,int rt,int l,int r,int k)
{
	if(l<=t[fl][rt].l&&t[fl][rt].r<=r)
	{
		t[fl][rt].val=k-t[fl][rt].val;
		t[fl][rt].lazy.push_back(k);
		return ;
	}
	pushdown(fl,rt);
	int mid=(t[fl][rt].l+t[fl][rt].r)>>1;
	if(l<=mid)update(fl,rt<<1,l,r,k);
	if(r>mid)update(fl,rt<<1|1,l,r,k);
}
int query(int fl,int rt,int l)
{
	if(t[fl][rt].l==t[fl][rt].r)
		return t[fl][rt].val;
	pushdown(fl,rt);
	int mid=(t[fl][rt].l+t[fl][rt].r)>>1;
	if(l<=mid)return query(fl,rt<<1,l);
	else return query(fl,rt<<1|1,l);
}
void solve()
{
	int n,m;
	cin>>n>>m;
	build(0,1,1,n);
	build(1,1,1,m);

	vector<vector<char>>mp(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int q;cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		update(0,1,1,x,x+1);
		update(0,1,x+1,n,x+1+n);
		update(1,1,1,y,1+y);
		update(1,1,y+1,m,y+1+m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			// cout<<mp[query(0,1,i)][query(1,1,j)];
			cout<<'['<<query(0,1,i)<<" "<<query(1,1,j)<<"] ";
		cout<<endl;
	}cout<<endl;
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
/*
1 2 3 4

5


*/