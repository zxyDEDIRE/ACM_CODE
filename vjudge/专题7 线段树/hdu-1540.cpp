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
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int n,m;
void solve()
{
	build(1,1,n);
	stack<int>s;
	while(m--)
	{
		char op;int x;
		cin>>op;
		if(op=='D'){
			cin>>x;
			s.push(x);
			update(1,x,x,0);
		}
		else if(op=='Q'){
			cin>>x;

			auto check=[&](int l,int r)->bool{
				return query(1,l,r)==r-l+1;
			};
			if(!check(x,x)){
				cout<<0<<endl;
				continue;
			}
			int l=1,r=x,ans_1=x;
			while(l<r-1){
				int mid=(l+r)>>1;
				if(check(mid,x))r=mid,ans_1=mid;
				else l=mid;
			}
			while(ans_1>1&&check(ans_1-1,x))ans_1--;

			l=x,r=n;
			int ans_2=x;
			while(l<r-1){
				int mid=(l+r)>>1;
				if(check(x,mid))l=mid,ans_2=mid;
				else r=mid;
			}
			while(ans_2<n&&check(x,ans_2+1))ans_2++;
			cout<<(ans_2-ans_1+1)<<endl;

		}
		else if(op=='R'){
			int x=s.top();s.pop();
			update(1,x,x,1);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m)
		solve();
	return 0;
}
/*
1 2 3 4 5 6 7
1 1 0 1 1 1 1
*/