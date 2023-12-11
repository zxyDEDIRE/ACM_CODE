/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	ll l,r,cnt,sum;
	node friend operator +(node a,node b){
		node c;
		c.l=a.l;
		c.r=b.r;
		c.cnt=a.cnt+b.cnt;
		c.sum=(a.sum+b.sum)%mod;
		return c;
	}
}t[maxn<<2];
void pushup(int k){
	t[k]=t[k<<1]+t[k<<1|1];
}
void build(int k,int l,int r){
	t[k].l=l;
	t[k].r=r;
	t[k].cnt=0;
	t[k].sum=0;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void modify(int k,int pos){
	if(t[k].l==t[k].r){
		t[k].cnt++;
		t[k].sum=t[k].cnt*pos;
		return;
	}
	int mid=(t[k].l+t[k].r)>>1;
	if(pos<=mid)
		modify(k<<1,pos);
	else 
		modify(k<<1|1,pos);
	pushup(k);
}
node query(int k,int l,int r){
	if(l<=t[k].l&&t[k].r<=r){
		return t[k];
	}
	int mid=(t[k].l+t[k].r)>>1;
	if(r<=mid)
		return query(k<<1,l,r);
	if(l>mid)
		return query(k<<1|1,l,r);
	return query(k<<1,l,r)+query(k<<1|1,l,r);
}
ll a[maxn];
ll km(ll a,ll b){
	a%=mod;
	ll ans=1;
	while(b){
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
const int N=2e5+10;
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=a[1];
	cout<<sum<<endl;
	build(1,1,N);
	modify(1,a[1]);
	for(int i=2;i<=n;i++){
		node now=query(1,1,a[i]);
		sum+=now.cnt*a[i]*2%mod;
		sum%=mod;
		now=query(1,a[i]+1,N);
		sum+=now.sum*2%mod;
		sum%=mod;
		modify(1,a[i]);
		sum+=a[i];
		sum%=mod;
		cout<<sum*km(i*i,mod-2)%mod<<'\n';
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;//in>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}