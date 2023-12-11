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
struct Seg{
	int l,r,v0,v1,lazy;
}t[maxn<<2];
string str;
int a1,a2,b1,b2;
int n,q;
void pushup(int rt){
	t[rt].v0=t[rt<<1].v0+t[rt<<1|1].v0;
	t[rt].v1=t[rt<<1].v1+t[rt<<1|1].v1;
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0};
	if(l==r){
		if(str[l-1]=='0')t[rt].v0++;
		else t[rt].v1++;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		swap(t[rt<<1].v0,t[rt<<1].v1);
		t[rt<<1].lazy^=1;
		swap(t[rt<<1|1].v0,t[rt<<1|1].v1);
		t[rt<<1|1].lazy^=1;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		swap(t[rt].v0,t[rt].v1);
		t[rt].lazy^=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
pii operator+(const pii a,const pii b){
	return {a.first+b.first,a.second+b.second};
}
pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return {t[rt].v0,t[rt].v1};
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	pii ans={0,0};
	if(l<=mid)ans=ans+query(rt<<1,l,r);
	if(r>mid)ans=ans+query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n>>q;
	cin>>a1>>a2>>b1>>b2;
	cin>>str;
	build(1,1,n);
	while(q--)
	{
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1)
		{
			update(1,l,r);
		}
		else
		{
			pii ans=query(1,r,r);
			if(ans.second)cout<<"Magical Splash Flare"<<endl;
			else cout<<"HoloPsychon"<<endl;
		}
	}
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