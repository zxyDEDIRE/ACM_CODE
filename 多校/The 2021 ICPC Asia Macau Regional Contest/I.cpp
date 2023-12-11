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
const int maxn=2e6+100;
int L[maxn];
class SAM{
public:
	vector<int>v[maxn];
	int ch[maxn][27],siz[maxn],len[maxn],fa[maxn];
	int id[maxn];
	
	bitset<maxn>vis;
	int f[maxn];
	int tot=1,np=1;
	ll ans;

	struct node{
		int x;
		bool operator<(const node&a)const{
			return L[a.x]>L[x];
		}
	};
	priority_queue<node>q;


	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<27;j++)
				ch[i][j]=0;siz[i]=len[i]=fa[i]=vis[i]=0;
		}tot=np=1;
	}
	int insert(const int&c,int _len,int _id){
		int p=np; np=++tot;
		L[np]=_len;id[np]=_id;
		len[np]=len[p]+1; siz[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				int nq=++tot;
				len[nq]=len[p]+1;
				fa[nq]=fa[q]; fa[q]=nq; fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
		return np;
	}
	// void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	// void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}
	void build_tree(){
		for(int i=2;i<=tot;i++)
			v[fa[i]].push_back(i);
	}
	/*  op=0本质不同子串 op=1位置不同子串  */
	void build(int op=0){
		build_tree();
		if(!op)
		{
			for(int i=1;i<=tot;i++)
				f[i]=siz[i]=1;
		}
		else get_siz(1);
		f[1]=siz[1]=0;
		get_f(1);
	}
	void get_kth(int k,int rt=1)
	{
		if(k>f[rt]){
			cout<<-1<<endl;
			return ;
		}
		if(k<=siz[rt]){cout<<"\n";return ;}
		k-=siz[rt];
		if(k==0){return;}
		for(int i=0;i<27;i++){
			if(ch[rt][i]){
				if(f[(ch[rt][i])]>=k){
					cout<<(char)(i+'a');
					get_kth(k,ch[rt][i]);
					return ;
				}
				else
					k-=f[ch[rt][i]];
			}
		}
		cout<<-1<<endl;
	}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<27;j++)
				if(ch[i][j])
					cout<<"ins "<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"fail "<<i<<" -> "<<fa[i]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"len["<<i<<"]="<<len[i]<<endl;
	}
	void query();
	void dfs(int x);
private:
	void get_siz(int x){
		for(auto y:v[x]){
			get_siz(y);
			siz[x]+=siz[y];
		}
		f[x]=siz[x];
	}
	void get_f(int x){
		if(vis[x])return ;
		vis[x]=1;
		for(int i=0;i<27;i++){
			int y=ch[x][i];
			if(!y)continue;
			get_f(y);
			f[x]+=f[y];
		}
	}
}sam;
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;
string p[maxn];
vector<int>v[maxn];
bitset<maxn>ok;
int n;
void SAM::dfs(int x)
{
	for(auto y:v[x])
		dfs(y);
	if(!v[x].size()){
		q.push({x});
		len[x]=min(len[x],L[x]);
	}
}
void SAM::query()
{
	dsu.init(tot);
	build_tree();
	dfs(1);
	cout<<"SDf"<<endl;
	while(!q.empty())
	{
		auto [x]=q.top();q.pop();
		if(x==0)continue;
		if(ok[x])continue;
		ok[x]=1;
		cout<<x<<endl;
		int y=fa[x];
		if(!id[y]||!dsu.same(x,y))
		{
			if(id[y])
			{
				dsu.merge(x,y);
				ans+=min(len[x],len[y]);
				L[y]=min(L[y],L[x]);
				len[y]=max(len[y],L[y]);
			}
			else
			{
				L[y]=L[x];
				len[y]=min(len[y],L[y]);
				
			}
			q.push({y});
			
		}
	}
	cout<<ans<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<str.size();j++)
			v[i].push_back(sam.insert(str[j]-'a',j+1,i));
	}
	sam.query();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
2
ab
aa
*/