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
void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt){
	ext[0]=0;
	for(int i=1,p0=0,p=0;i<=lens;i++){
		ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
		while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
		if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
	}
}
void kmp(char *s,int len,int *nxt)
{
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}

// int unit;
// struct node {
//   int l, r, id;
//   bool operator<(const node &x) const {
//     return l / unit == x.l / unit
//                ? (r == x.r ? 0 : ((l / unit) & 1) ^ (r < x.r))
//                : l < x.l;
//   }
// }p[maxn];
namespace Seg{
	struct Seg{
		int l,r,ma;
	}t[maxn<<2];
	int res;
	// void f(int rt){};
	void pushup(int rt){
		t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	};
	void build(int rt,int l,int r,int *ext){
		t[rt]={l,r,0};
		if(l==r){
			t[rt].ma=ext[l]+l-1;
			return ;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid,ext);
		build(rt<<1|1,mid+1,r,ext);
		pushup(rt);
	}
	void update(int rt,int l,int r,int k){
		if(l<=t[rt].l&&t[rt].r<=r){
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)update(rt<<1,l,r,k);
		if(r>mid)update(rt<<1|1,l,r,k);
	}
	void query(int rt,int l,int r){
		if(t[rt].ma<r)return ;
		if(res<r)return ;
		if(l<=t[rt].l&&t[rt].r<=r){
			if(t[rt].l==t[rt].r){
				res=t[rt].l;
				return ;
			}
			query(rt<<1,l,r);
			query(rt<<1|1,l,r);
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)query(rt<<1,l,r);
		if(r>mid)query(rt<<1|1,l,r);
	}
};

int nxt[maxn],ext[maxn],kxt[maxn];
char s[maxn],t[maxn];
ll w[maxn],pre[maxn];
ll c1[maxn];
ll c2[maxn];
int n,q;

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		pre[i]=pre[i-1]+w[i];
	}
	exkmp(s,n,s,n,nxt,nxt);
	exkmp(t,n,s,n,ext,nxt);
	kmp(s,n,kxt);
	// {
	// 	cout<<"nxt:"<<endl;
	// 	for(int i=1;i<=n;i++)
	// 		cout<<"nxt["<<i<<"]="<<nxt[i]<<endl;
	// 	cout<<"ext:"<<endl;
	// 	for(int i=1;i<=n;i++)
	// 		cout<<"ext["<<i<<"]="<<ext[i]<<endl;
	// 	cout<<"kxt:"<<endl;
	// 	for(int i=1;i<=n;i++)
	// 		cout<<"kxt["<<i<<"]="<<kxt[i]<<endl;
	// 	cout<<endl;
	// }//Debug nxt ext kxt

	for(int i=1;i<=n;i++)
		c1[i]=w[i];
	for(int i=1;i<=n;i++)
		c1[i]+=c1[kxt[i]];
	for(int i=1;i<=n;i++)
		c1[i]+=c1[i-1];

	for(int i=1;i<=n;i++)
		c2[i]=c2[i-1]+pre[ext[i]];

	// {
	// 	cout<<"C1:"<<endl;
	// 	for(int i=1;i<=n;i++)
	// 		cout<<"c1["<<i<<"]="<<c1[i]<<endl;
	// 	cout<<endl;
	// }//Debug c1

	Seg::build(1,1,n,ext);
	auto Find=[&](int l,int r)->int{
		Seg::res=r+1;
		Seg::query(1,l,r);
		// cout<<"Find("<<l<<","<<r<<")="<<Seg::res<<endl;
		return Seg::res;
	};
	// Find(3,4);
	// Find(3,6);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int mid=Find(l,r);
		// cout<<mid-1<<" "<<l-1<<" "<<c2[mid-1]-c2[l-1]<<endl;
		// cout<<mid<<" "<<r<<" "<<c1[r-mid+1]<<endl;
		ll ans=c2[mid-1]-c2[l-1]+c1[r-mid+1];
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}