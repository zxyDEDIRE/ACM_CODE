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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6+100;
class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int len[maxn];
	int id[maxn];
	int in[maxn];
	vector<pii>v[maxn];
	ll f[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=nxt[i]=id[i]=0;
			for(int j=0;j<26;j++)
				ch[i][j]=0;
		}
		indx=0;
	}
	void insert(const string &str,int x){
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'a';
			if(!ch[rt][tmp]){
				ch[rt][tmp]=++indx;
				// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> "<<indx<<endl;
			}
			rt=ch[rt][tmp];
		}
		val[rt]=1;
		len[rt]=str.size();
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
					in[nxt[rt]]++;

					val[rt]+=val[nxt[rt]];
					len[rt]+=len[nxt[rt]];

					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
	}
	void query(const string&s,int _id)
	{
		int rt=0;
		ll ans=0;
		for(int i=0;i<s.size();i++)
		{
			int tmp=s[i]-'a';
			rt=ch[rt][tmp];
			ll _l=i*val[rt]-len[rt]+val[rt];
			ll _r=s.size()-i-1;
			ans+=(_l+val[rt])*(_r+1)%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
}acam;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string str;cin>>str;
		acam.insert(str,i);
	}
	acam.build();
	for(int i=1;i<=m;i++){
		string str;cin>>str;
		acam.query(str,i);
	}
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
aababc
*/