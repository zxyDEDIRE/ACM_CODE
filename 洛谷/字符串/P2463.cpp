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
	// vector<int>v[maxn];
	int siz[maxn],len[maxn],fa[maxn];
	map<int,int>ch[maxn];
	int main_in[maxn];
	int in[maxn];
	int mi[maxn];
	int f[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;siz[i]=len[i]=fa[i]=0;
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
				// memcpy(ch[nq],ch[q],sizeof(ch[q]));
				ch[nq]=ch[q];
			}
		}
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}
	void insert(const vector<int>&s){
		for(auto i:s)
			insert(i);
		for(int i=1;i<=tot;i++)
			mi[i]=INF;
	}
	void build_tree(){
		for(int i=2;i<=tot;i++){
			// v[fa[i]].push_back(i);
			main_in[fa[i]]++;
		}
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
	void match(const vector<int>&s);
	void update();
	void query();
}sam;
int n,m;
void SAM::match(const vector<int>&s)
{
	int rt=1;
	int length=0;
	for(int i=0;i<(int)s.size();i++)
	{
		int tmp=s[i];
		while(rt &&!ch[rt].count(tmp))
			rt=fa[rt],length=len[rt];
		if(!rt)rt=1;
		else{
			rt=ch[rt][tmp];
			length++;
		}
		f[rt]=max(f[rt],length);
	}
}
void SAM::update()
{
	queue<int>q;
	for(int i=1;i<=tot;i++)
	{
		in[i]=main_in[i];
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		mi[x]=min(mi[x],f[x]);
		int y=fa[x];
		if(f[x]>=len[y])
			f[y]=len[y];
		in[y]--;
		if(!in[y])q.push(y);
	}
	for(int i=1;i<=tot;i++)f[i]=0;
}
void SAM::query()
{
	int ma=0;
	for(int i=1;i<=tot;i++)
		ma=max(ma,mi[i]);
	cout<<ma+1<<endl;;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		cin>>m;
		vector<int>v(m);
		vector<int>p(m-1);

		for(int j=0;j<m;j++)
			cin>>v[j];
		for(int j=0;j<m-1;j++)
			p[j]=v[j+1]-v[j];
		if(i==1){
			sam.insert(p);
			sam.build_tree();
		}
		else
		{
			sam.match(p);
			sam.update();
		}
	}
	sam.query();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}