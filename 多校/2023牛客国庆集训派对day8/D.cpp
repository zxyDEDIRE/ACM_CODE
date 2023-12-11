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
vector<int>v[maxn];
int t[maxn][30],tot=1;
string s[maxn];
int vis[maxn];
int in[maxn];
int n,m;
void insert(int id,string&str)
{
	int len=str.size();
	v[id].resize(len+1);
	int rt=1;
	for(int i=0;i<len;i++)
	{
		v[id][i]=rt;
		int tmp=str[i]-'a';
		if(!t[rt][tmp])
			t[rt][tmp]=++tot;
		rt=t[rt][tmp];
		in[rt]++;
	}
	vis[rt]++;
}
void update(int x,int y,char ch)
{
	char old=s[x][y-1];
	if(old==ch)return ;

	int tmp_new=ch-'a';
	int tmp_old=s[x][y-1]-'a';
	s[x][y-1]=ch;

	int rt=v[x][y-1];
	t[rt][tmp_new]=++tot;


	if(vis[t[rt][tmp_old]])
	{
		vis[t[rt][tmp_old]]--;
		vis[t[rt][tmp_new]]++;
	}

	int a=t[rt][tmp_new];
	int b=t[rt][tmp_old];
	for(int j=0;j<26;j++)
	{
		t[a][j]=t[b][j];
	}

	in[t[rt][tmp_old]]--;
	in[t[rt][tmp_new]]++;
	if(in[t[rt][tmp_old]]==0)
		t[rt][tmp_old]=0;
	v[x][y]=tot;
}
int th[maxn];


class SAM{
public:
	vector<int>v[maxn];
	int ch[maxn][26],siz[maxn],len[maxn],fa[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;
			siz[i]=len[i]=fa[i]=0;
			v[i].clear();
		}tot=np=1;
		ans=0;
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
	void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}
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
		// build(1);
		for(int i=1;i<=tot;i++)
			cout<<siz[i]<<" ";cout<<endl;
	}
	void query();
private:
	void get_siz(int x){
		for(auto y:v[x]){
			get_siz(y);
			siz[x]+=siz[y];
		}
	}
}sam;
void SAM::query()
{
	th[1]=1;
	for(int i=1;i<=tot;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(t[i][j]&&th[i])
			{
				int rt=th[i];
				if(ch[rt][j])
				{
					// cout<<"SDf"<<endl;
					th[t[i][j]]=ch[rt][j];
					ans+=vis[t[i][j]]*siz[ch[rt][j]];
					// cout<<t[i][j]<<" "<<ch[rt][j]<<endl;
					// cout<<vis[t[i][j]]<<" "<<siz[ch[rt][j]]<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=tot;i++)
		th[i]=0;
}
void Q()
{
	cout<<"tot "<<tot<<endl;

	for(int i=1;i<=tot;i++)
		for(int j=0;j<26;j++)
			if(t[i][j])
			cout<<"IN "<<i<<" --"<<(char)(j+'a')<<"--> "<<t[i][j]<<endl;
	for(int i=1;i<=tot;i++)
		cout<<vis[i]<<" ";cout<<endl;
		cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		insert(i,s[i]);
	}
	// cout<<"tot "<<tot<<endl;
	// for(int i=1;i<=tot;i++)
	// 	for(int j=0;j<26;j++)
	// 		if(t[i][j])
	// 		cout<<"IN "<<i<<" --"<<(char)(j+'a')<<"--> "<<t[i][j]<<endl;
	// for(int i=1;i<=tot;i++)
	// 	cout<<vis[i]<<" ";cout<<endl;
	// 	cout<<endl;
	while(m--)
	{
		int op,x,y;char c;
		string str;
		cin>>op;
		if(op==0)
		{
			cin>>x>>y>>c;
			update(x,y,c);
			// Q();
		}
		else if(op==1)
		{
			cin>>str;
			sam.clear();
			sam.insert(str);
			sam.build(1);
			// sam.debug();
			sam.query();
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
/*
5 2
ab
b
aa
a
cba
0 1 2 c
1 aba
*/