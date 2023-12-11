#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int ml[maxn];
	int mr[maxn];
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
	void insert(const int&c,int pos){
		int p=np; np=++tot;
		f[np]=pos;ml[tot]=INF,mr[tot]=0;
		len[np]=len[p]+1; siz[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				int nq=++tot;
				f[tot]=-1;ml[tot]=INF,mr[tot]=0;
				len[nq]=len[p]+1;
				fa[nq]=fa[q]; fa[q]=nq; fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
	}
	// void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){
		for(int i=0;i<(int)s.size();i++)
			insert(s[i]-'a',i+1);
	}
	void build_tree(){
		for(int i=2;i<=tot;i++)
			v[fa[i]].push_back(i);
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
	void dfs(int x);
	void query();
}sam;
string str;
int n;
void SAM::dfs(int x=1)
{
	if(f[x]!=-1)
	{
		ml[x]=min(ml[x],f[x]);
		mr[x]=max(mr[x],f[x]);
	}
	for(auto y:v[x])
	{
		dfs(y);
		ml[x]=min(ml[x],ml[y]);
		mr[x]=max(mr[x],mr[y]);
	}
}
void SAM::query()
{
	int cnt=0;
	for(int i=2;i<=tot;i++)
		if(mr[i]-ml[i]>len[fa[i]])
			cnt+=min(len[i],mr[i]-ml[i])-len[fa[i]];
	cout<<cnt<<endl;
}
void solve()
{
	// cin>>str;
	while(cin>>str&&str!="#")
	{
		sam.clear();
		sam.insert(str);
		sam.build_tree();
		sam.dfs();
		sam.query();
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