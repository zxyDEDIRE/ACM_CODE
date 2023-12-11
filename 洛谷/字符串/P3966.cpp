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
class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn];
	int in[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=nxt[i]=0;
			for(int j=0;j<26;j++)
				ch[i][j]=0;
		}
		indx=0;
	}
	void insert(const string &str,int x){
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'a';
			// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> ";
			if(!ch[rt][tmp])ch[rt][tmp]=++indx;
			rt=ch[rt][tmp];
			// cout<<rt<<endl;
			cnt[rt]++;
		}
		id[x]=rt;
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
					in[ch[nxt[x]][i]]++;
					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
	}
	void topsort()
	{
		queue<int>q;
		for(int i=1;i<=indx;i++)
			if(!in[i])q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			int y=nxt[x];
			cnt[y]+=cnt[x];
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	void query(int n)
	{
		topsort();
		for(int i=1;i<=n;i++)
			cout<<cnt[id[i]]<<endl;
	}
}acam;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		acam.insert(str,i);
	}
	acam.build();
	acam.query(n);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}