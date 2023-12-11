/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
}t[maxn];
vector<pii>v;
int n,m;
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r){
	if(l>r)return 0;
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			v.push_back({x,i});
		}
	sort(v.begin(),v.end(),[&](auto a,auto b){
		return a.first<b.first;
	});
	
	build(1,0,n+1);

	ll ans=0;

	for(int i=0;i<v.size();i++)
	{
		auto now=v[i].second;
		int _x = query(1,now,n);
		int _y = query(1,now+1,n);
		ans += _y + 1ll*(n-now)*(_x-_y+1);
		update(1,now);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
3 3
1 2 4
3 5 7
6 8 9

1 2 3 4 5 7
3 5 6 7 8 9
*/