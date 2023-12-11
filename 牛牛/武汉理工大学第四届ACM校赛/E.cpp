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
class Seg{
public:
	struct Seg_node{
		int l,r,val;
	};
	vector<Seg_node>t;
	Seg(int l,int r){
		t.resize(r*4+10);
		build(1,l,r);
	}
	void pushup(int rt){
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	};
	void pushdown(int rt){};
	void build(int rt,int l,int r)
	{
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
	int query(int rt,int l,int r)
	{
		if(l<=t[rt].l&&t[rt].r<=r){
			return t[rt].val;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=0;
		if(l<=mid){
			ans+=query(rt<<1,l,r);
		}
		if(r>mid){
			ans+=query(rt<<1|1,l,r);
		}
		return ans;
	}
	void update(int rt,int l,int r,int k){
		if(l<=t[rt].l&&t[rt].r<=r){
			t[rt].val=k;
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid){update(rt<<1,l,r,k);}
		if(r>mid){update(rt<<1|1,l,r,k);}
		pushup(rt);
	}
};
map<string,int>mp;
int n,q,top;
void solve()
{
	cin>>n;
	top=n;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		mp[str]=n-i+1;
	}
	cin>>q;
	Seg T(1,n*10);
	cout<<q<<endl;
	while(q--)
	{
		string str;
		cin>>str;
		int x=mp[str];
		if(x==top){
			cout<<1<<endl;
			continue;
		}
		top++;
		T.update(1,x,x,0);
		mp[str]=top;
		cout<<T.query(1,x,top)<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}