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
	int l,r,val,lazy;
}t[maxn];
vector<int>v[maxn];
int a[maxn],siz[maxn],tot;
string s;
int op;
int n,m,q;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void f(int rt,int w){
	t[rt].val+=w*(t[rt].r-t[rt].l+1);
	t[rt].lazy+=w;
}
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt){
	if(t[rt].lazy){
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		f(rt,1);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int Squery(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=Squery(rt<<1,l,r);
	if(r>mid)ans+=Squery(rt<<1|1,l,r);
	return ans;
}
void de(int rt){
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return ;
	de(rt<<1);de(rt<<1|1);
}

class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn];
	int in[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=nxt[i]=0;
			for(int j=0;j<26;j++)
				ch[i][j]=0;
			v[i].clear();
		}
		indx=0;
		tot=0;
	}
	void insert(const string &str,int x){
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'a';
			if(!ch[rt][tmp]){
				ch[rt][tmp]=++indx;
				// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> "<<indx<<endl;
			}
			rt=ch[rt][tmp];
		}
		val[rt]++;
		id[x]=rt;
	}
	void build()
	{
		queue<int>q;
		for(int i=0;i<26;i++)
			if(ch[0][i])
				q.push(ch[0][i]);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<26;i++){
				int &rt=ch[x][i];
				if(!rt) rt=ch[nxt[x]][i];
				else{
					nxt[rt]=ch[nxt[x]][i];
					in[nxt[rt]]++;
					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
		for(int rt=1;rt<=indx;rt++){
			v[nxt[rt]].push_back(rt);
			// cout<<"nxt "<<nxt[rt]<<" -> "<<rt<<endl;
		}
	}
	void query(const string&s)
	{
		int rt=0,ans=0;
		for(int i=0;i<(int)s.size();i++)
		{
			rt=ch[rt][s[i]-'a'];
			ans+=Squery(1,a[rt],a[rt]);
			// cout<<"query "<<rt<<" "<<a[rt]<<" "<<Squery(1,a[rt],a[rt])<<endl;
		}
		cout<<ans<<endl;
	}
}acam;

void dfs(int x){
	a[x]=++tot;
	siz[x]=1;
	for(auto y:v[x]){
		dfs(y);
		siz[x]+=siz[y];
	}
}
void solve()
{
	cin>>n>>q;
	m=n;
	acam.clear();
	for(int i=1;i<=n;i++){
		cin>>s;
		acam.insert(s,i);
	}
	vector<pair<int,string>>Q;
	for(int i=1;i<=q;i++){
		cin>>op>>s;
		if(op==1){
			acam.insert(s,++m);
			Q.push_back({m,"!"});
		}
		else Q.push_back({op,s});
	}

	acam.build();
	dfs(0);
	build(1,1,tot);
	for(int i=1;i<=n;i++){
		int x=acam.id[i];
		update(1,a[x],a[x]+siz[x]-1);
	}

	for(auto &[op,s]:Q)
	{
		if(s=="!")
		{
			int x=acam.id[op];
			update(1,a[x],a[x]+siz[x]-1);
			// cout<<"update "<<x<<" "<<a[x]<<" "<<a[x]+siz[x]-1<<" "<<siz[x]<<endl;
		}
		else
		{
			// de(1);
			acam.query(s);
			// cout<<endl;
		}
	}

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}