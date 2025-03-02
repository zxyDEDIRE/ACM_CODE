#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=2e6+100;
struct Manacher{
	char ch[maxn];
	int lc[maxn];
	int N;
	void init(char *s){
		int n=strlen(s+1);
		// puts(s+1);
		ch[n*2+1]='#';
		ch[0]='@';
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]='#';
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
		// printf("%d\n",ma);
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
	bool check(int l,int r){
		int mid=(l*2+r*2)/2;
		if(r*2-mid+1>lc[mid])return 0;
		return 1;
	}
}Manch;
struct Seg{
	int l,r;ll val;
}t[maxn<<2];
ll pre[maxn];
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=pre[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=-INF;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
char s[maxn];
ll val[30];
int n;
void solve()
{
	cin>>n;
	for(int i=0;i<26;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		pre[i]=pre[i-1]+val[s[i]-'a'];
	}
	s[n+1]='\0';
	Manch.init(s);
	Manch.manacher();
	build(1,1,n);

	auto getLR=[&](int mid,int op)->pii{
		int l=0,r=n,ans=l;
		auto check=[&](int x)->bool{
			/*
			换哈希 
			*/
			int _l = mid-x+1;
			int _r = mid+x-op;
			if(_l<1||_l>n||_r<1||_r>n)return 0;
			return Manch.check(_l,_r);
		};
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid))l=mid,ans=mid;
			else r=mid;
		}
		while(check(ans+1))ans++;
		int _l = mid-ans+1;
		int _r = mid+ans-op;
		return pii{_l,_r};
	};


	ll res=0;
	for(int x=1;x<=n;x++)
	{
		pii nowR = getLR(x,1);
		pii nowL = getLR(x,0);
		int l,r;
		// cout<<x<<endl;
		// cout<<nowR.first<<" "<<nowR.second<<endl;
		// cout<<nowL.first<<" "<<nowL.second<<endl;
		l=nowR.first;r=nowR.second;
		res=max(res,val[s[x]-'a']);

		if(l!=r)
		{
			ll now=query(1,x+1,r);
			ll sum=val[s[x]-'a']+2*(now-pre[x]);
			res=max(res,sum);
		}


		l=nowL.first;r=nowL.second;
		if(l<r)
		{
			ll now=query(1,x+1,r);
			ll sum=2*(now-pre[x]);
			res=max(res,sum);
		}
	}

	cout<<res<<endl;
}
signed main(){
 // freopen("./data/50.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5
-10 -500 -100 500 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
cbdadbcdddd
*/
/*
10 9 5 4

0 超级签到
1 
2 
3 铜牌差点
4 铜牌签到
5 铜牌中档
*/