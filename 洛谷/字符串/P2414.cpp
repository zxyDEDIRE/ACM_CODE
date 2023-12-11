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
vector<pii>g[maxn];
vector<int>v[maxn];
char str[maxn];
int id[maxn],di[maxn],siz[maxn],tot;
int ans[maxn];
int n,m;
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
	void build(int rt,int l,int r)
	{
		t[rt]={l,r,0};
		if(l==r)return ;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	int query(int rt,int l,int r)
	{
		if(l<=t[rt].l&&t[rt].r<=r){
			return t[rt].val;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=0;
		if(l<=mid)ans+=query(rt<<1,l,r);
		if(r>mid)ans+=query(rt<<1|1,l,r);
		return ans;
	}
	void update(int rt,int l,int k){
		if(t[rt].l==t[rt].r){
			t[rt].val+=k;
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)update(rt<<1,l,k);
		else update(rt<<1|1,l,k);
		pushup(rt);
	}
	void dfs(int rt);
};
class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int fa[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=nxt[i]=0;
			for(int j=0;j<26;j++)
				ch[i][j]=0;
		}
		indx=0;
	}
	void insert(){
		int rt=0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='P')
			{
				val[rt]++;
				n++;
				id[n]=rt;
			}
			else if(str[i]=='B')
			{
				rt=fa[rt];
			}
			else
			{
				if(!ch[rt][str[i]-'a']){
					ch[rt][str[i]-'a']=++indx;
					// cout<<rt<<" "<<str[i]<<" "<<indx<<endl;
					fa[indx]=rt;
				}
				rt=ch[rt][str[i]-'a'];
			}
		}
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
					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
		for(int rt=1;rt<=indx;rt++){
			v[rt].push_back(nxt[rt]);
			v[nxt[rt]].push_back(rt);
		}
	}
}acam;
void dfs(int x,int f)
{
	id[x]=++tot;
	di[tot]=x;
	siz[x]=1;
	for(auto y:v[x])
		if(y^f){
			dfs(y,x);
			siz[x]+=siz[y];
		}
}
void Seg::dfs(int rt){
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return ;
	Seg::dfs(rt<<1);
	Seg::dfs(rt<<1|1);
}
void solve()
{
	cin>>str;
	acam.insert();
	acam.build();
	dfs(0,0);
	Seg seg(1,tot);
	cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[y].push_back({x,i});
	}
	for(int i=0,cnt=0,rt=0;i<strlen(str);i++)
	{
		if(str[i]=='P')
		{
			cnt++;
			for(auto [x,I]:g[cnt])
			{
				// seg.dfs(1);
				x=acam.id[x];
				// cout<<"id "<<x<<" "<<I<<endl;
				// cout<<id[x]<<" "<<id[x]+siz[x]-1<<endl;
				ans[I]=seg.query(1,id[x],id[x]+siz[x]-1);
				// cout<<ans[I]<<endl;
				// cout<<endl;
			}
		}
		else if(str[i]=='B')
		{
			seg.update(1,id[rt],-1);
			rt=acam.fa[rt];
		}
		else
		{
			int tmp=str[i]-'a';
			rt=acam.ch[rt][tmp];
			// cout<<"Add "<<id[rt]<<endl;
			seg.update(1,id[rt],1);
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
abPababP
*/