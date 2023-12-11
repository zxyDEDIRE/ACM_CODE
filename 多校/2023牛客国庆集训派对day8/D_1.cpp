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
class SAM{
public:
	vector<int>v[maxn];
	int ch[maxn][26],siz[maxn],len[maxn],fa[maxn];
	bitset<maxn>vis;
	int f[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;siz[i]=len[i]=fa[i]=vis[i]=0;
			v[i].clear();
		}tot=np=1;
	}
	void insert(const int&c){
		int p=np; np=++tot;
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
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){
		for(int i=0;i<(int)s.size();i++)
			insert(s[i]-'a');
		build(1);
	}
	void build_tree(){
		for(int i=2;i<=tot;i++)
			v[fa[i]].push_back(i);
	}
	/*  op=0本质不同子串 op=1位置不同子串  */
	void build(int op=0){
		build_tree();
		get_siz(1);
		siz[1]=0;
	}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<26;j++)
				if(ch[i][j])
					cout<<"ins "<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"fail "<<i<<" -> "<<fa[i]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"len["<<i<<"]="<<len[i]<<endl;
	}
	int query(string &str);
private:
	void get_siz(int x){
		for(auto y:v[x]){
			get_siz(y);
			siz[x]+=siz[y];
		}
		f[x]=siz[x];
	}
}sam;

string s[maxn];
int n,m;

int SAM::query(string &str)
{
	int rt=1;
	for(int i=0;i<(int)str.size();i++)
	{
		if(!ch[rt][str[i]-'a'])return 0;
		rt=ch[rt][str[i]-'a'];
	}
	return siz[rt];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	while(m--)
	{
		int op,x,y;char ch;
		string str;
		cin>>op;
		if(op==0)
		{
			cin>>x>>y>>ch;
			s[x][y-1]=ch;
		}
		else
		{
			sam.clear();
			cin>>str;
			sam.insert(str);
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=sam.query(s[i]);
			cout<<ans<<endl;
		}
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