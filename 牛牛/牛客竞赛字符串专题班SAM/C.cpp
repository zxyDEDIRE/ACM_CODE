#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
	int st[maxn][20];
	int f[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;siz[i]=len[i]=fa[i]=vis[i]=0;
		}tot=np=1;
	}
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1; siz[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1,f[len[np]]=np;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q,f[len[np]]=np;
			else{
				int nq=++tot;
				len[nq]=len[p]+1;
				fa[nq]=fa[q]; fa[q]=nq; fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				f[len[np]]=np;
			}
		}
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}
	void build_tree(){
		for(int i=2;i<=tot;i++){
			v[fa[i]].push_back(i);
		}
		get_siz(1);
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
		for(int i=0;i<26;i++){
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
			for(int j=0;j<26;j++)
				if(ch[i][j])
					cout<<"ins "<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"fail "<<i<<" -> "<<fa[i]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"len["<<i<<"]="<<len[i]<<endl;
	}
	void query(int ,int );
private:
	void get_siz(int x,int fa=0){
		st[x][0]=fa;
		for(int i=1;i<20;i++)
			st[x][i]=st[st[x][i-1]][i-1];
		for(auto y:v[x]){
			get_siz(y,x);
			siz[x]+=siz[y];
		}
	}
	void get_f(int x){
		if(vis[x])return ;
		vis[x]=1;
		for(int i=0;i<26;i++){
			int y=ch[x][i];
			if(!y)continue;
			get_f(y);
			f[x]+=f[y];
		}
	}
}sam;
void SAM::query(int l,int r){
	int rt=f[r];
	int now=0;
	for(int i=19;i>=0;i--)
		if(len[st[rt][i]]>=r-l+1)
			rt=st[rt][i];
	cout<<siz[rt]<<"\n";
}
void solve()
{
	string str;
	cin>>str;
	sam.insert(str);
	// sam.debug();
	sam.build_tree();
	int q;cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		sam.query(l,r);
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