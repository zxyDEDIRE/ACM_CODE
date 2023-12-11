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
int norm(int x, int P) {
	if (x < 0) x += P;
	if (x >= P) x -= P;
	return x;
}
template<const int P> 
struct Mint {
	int val;
	Mint(int x = 0) {val = norm(x, P);}
	int v() const {return val;}
	Mint inv() const {return qpow(*this, P - 2);}
	Mint operator - () const {return Mint(norm(P - val, P));}
	Mint operator += (const Mint &rhs) {val = norm(val + rhs.val, P); return *this;}
	Mint operator -= (const Mint &rhs) {val = norm(val - rhs.val, P); return *this;}
	Mint operator *= (const Mint &rhs) {val = 1ll * val * rhs.val % P; return *this;}
	Mint operator /= (const Mint &rhs) {return *this *= rhs.inv();}
	friend Mint operator + (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res += rhs; return res;}
	friend Mint operator - (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res -= rhs; return res;}
	friend Mint operator * (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res *= rhs; return res;}
	friend Mint operator / (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res /= rhs; return res;}
	friend istream& operator >> (istream& is, Mint &x) {
		int v;
		is >> v;
		x = norm(v, P);
		return is;
	}
	friend ostream& operator << (ostream& os, const Mint &x) {
		return os << x.v();
	}
};
using mint = Mint<mod>;
int ch[maxn][10],nxt[maxn];
int val[maxn],cnt[maxn];
int f[maxn][10][20];
mint w[maxn][10][20];
int id[maxn];
int in[maxn];
int root=0,indx=0;
int n;

void insert(const string &str,int w){
	int rt=0;
	for(int i=0;i<str.size();i++){
		int tmp=str[i]-'0';
		if(!ch[rt][tmp]){
			ch[rt][tmp]=++indx;
			// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> "<<indx<<endl;
		}
		rt=ch[rt][tmp];
	}
	val[rt]+=w;
}
void build()
{
	queue<int>q;
	for(int i=0;i<10;i++)
		if(ch[0][i])
			q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<10;i++){
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
	for(int i=0;i<=indx;i++)
		for(int j=0;j<10;j++)
			f[i][j][0]=ch[i][j],w[i][j][0]=val[ch[i][j]];
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=indx;i++)
		{
			for(int c=0;c<10;c++)
			{
				f[i][c][j]=f[f[i][c][j-1]][c][j-1];
				w[i][c][j]=w[i][c][j-1]+w[f[i][c][j-1]][c][j-1];
			}
		}
	}
}
mint ans[maxn];
pii seg[maxn];
int sta[maxn];
int nowpos[maxn];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;int w;
		cin>>str>>w;
		insert(str,w);
	}
	build();
	string t;
	mint sum=0;
	int tp=0;
	cin>>t;
	for(int i=1,rt=0;i<t.size();i++)
	{
		int tmp=t[i]-'0';
		rt=ch[rt][tmp];
		sum+=val[rt];
		++tp;
		ans[tp]=sum;
		seg[tp]={i,i};
		sta[tp]=tmp;
	}
	int q;
	cin>>q;
	auto go=[&](int p,int c,int step)->pii{
		mint ans=0;
		for(int i=20;i>=0;i--)
			if((step>>i)&1)ans+=w[p][c][i],p=f[p][c][i];
		return {ans.v(),p};
	};
	while(q--)
	{
		int op,l,c;
		cin>>op;
		if(op==1)
		{
			cin>>l>>c;
			int ps=t.size()-l;
			while(tp&&seg[tp].first>=ps)tp--;
			if(tp)
			{
				seg[tp].second=ps-1;
				auto [tot,p]=go(nowpos[tp-1],sta[tp],ps-seg[tp].first);
				nowpos[tp]=p;
				ans[tp]=ans[tp-1]+tot;
			}
			tp++;
			sta[tp]=c;
			seg[tp]={ps,t.size()-1};
			auto [tot,p]=go(nowpos[tp-1],sta[tp],l);
			ans[tp]=ans[tp-1]+tot;
			nowpos[tp]=p;
		}
		else
		{
			cin>>l;
			int ll=1,rr=tp;
			int tt;
			while(ll<=rr)
			{
				int md=ll+rr>>1;
				if(seg[md].first<=l){
					ll=md+1;
					tt=md;
				}
				else rr=md-1;
			}
			mint ANS=ans[tt-1]+go(nowpos[tt-1],sta[tt],l-seg[tt-1].second).first;
			cout<<ANS<<endl;
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