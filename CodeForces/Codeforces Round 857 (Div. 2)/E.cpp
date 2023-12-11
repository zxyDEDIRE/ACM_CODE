/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
int n;
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	cin>>n;
	vector<vector<int>>v;
	vector<int>last;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		vector<int>p;
		while(k--){
			int x;cin>>x;
			if(p.size()==0||x>p.back())
				p.push_back(x);
		}
		v.push_back(p);
	}
	sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
		return a.back()<b.back();
	});
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		int now=0;
		for(int j=v[i].size()-1;j>=0;j--)
		{
			cnt++;
			now=max(now,cnt+query(1,1,v[i][j]-1));
		}
		int x=v[i].back();
		if(query(1,x,x)<now)update(1,x,now),last.push_back(x);
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	for(auto i:last)
		update(1,i,0);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	build(1,0,200000);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}