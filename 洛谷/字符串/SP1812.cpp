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
	int ch[maxn][26],siz[maxn],len[maxn],fa[maxn];
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
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){
		for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');
		for(int i=0;i<=tot;i++)
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
	void match(const string&s);
	void query();
}sam;
string s;
void SAM::match(const string&s)
{
	queue<int>q;
	for(int i=1;i<=tot;i++){
		f[i]=0,in[i]=main_in[i];
		if(!in[i])q.push(i);
	}
	int rt=1;
	int length=0;
	for(int i=0,tmp;i<(int)s.size();i++)
	{
		tmp=s[i]-'a';
		while(rt&&!ch[rt][tmp])
			rt=fa[rt],length=len[rt];
		if(!rt)rt=1;
		else{
			rt=ch[rt][tmp];length++;
		}
		f[rt]=max(f[rt],length);
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
}
void SAM::query()
{
	int ma=0;
	for(int i=1;i<=tot;i++)
		ma=max(ma,mi[i]);
	cout<<ma<<endl;
}
int n;
void solve()
{
	cin>>n;
	sam.clear();
	cin>>s;
	sam.insert(s);
	for(int i=2;i<=n;i++){
		cin>>s;
		sam.match(s);
	}
	sam.query();

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