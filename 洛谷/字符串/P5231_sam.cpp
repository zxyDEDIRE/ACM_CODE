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
const int maxn=2e7+100;
class SAM{
public:
	int ch[maxn][4],fa[maxn],len[maxn];
	int tot=1,np=1;
	ll ans;
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1;
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
	int f(char ch){
		if(ch=='E')return 0;
		else if(ch=='S')return 1;
		else if(ch=='W')return 2;
		else return 3;
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){
		for(int i=0;i<(int)s.size();i++)
			insert(f(s[i]));
	}
	int match(const string&s);
}sam;
int m,n;
string s;
int SAM::match(const string&s)
{
	int rt=1,length=0;
	for(auto i:s)
	{
		int tmp=f(i);
		if(!ch[rt][tmp])break;
		rt=ch[rt][tmp];
		length++;
	}
	return length;
}
void solve()
{
	cin>>m>>n;
	cin>>s;
	sam.insert(s);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		cout<<sam.match(s)<<endl;
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