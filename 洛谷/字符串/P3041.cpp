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
class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int dp[2100][430];
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
			int tmp=str[i]-'A';
			if(!ch[rt][tmp]){
				ch[rt][tmp]=++indx;
				// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> "<<indx<<endl;
			}
			rt=ch[rt][tmp];
		}
		val[rt]++;
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
					in[nxt[rt]]++;
					val[rt]+=val[nxt[rt]];
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
		for(int i=0;i<=n;i++)
			for(int j=0;j<=indx;j++)
				dp[i][j]=-INF;
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=indx;j++)
				for(int k=0;k<26;k++){
					dp[i][ch[j][k]]=max(dp[i][ch[j][k]],dp[i-1][j]+val[ch[j][k]]);
					// cout<<"dp["<<i<<","<<ch[j][k]<<"]="<<dp[i][ch[j][k]]<<" dp["<<i-1<<","<<j<<"]="<<dp[i-1][j]<<" val["<<ch[i][k]<<"]="<<val[ch[j][k]]<<endl;
				}
		}
		int ma=0;
		for(int i=0;i<=indx;i++)
			ma=max(ma,dp[n][i]);
		cout<<ma<<endl;
	}
}acam;
string s;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		acam.insert(s,i);
	}
	acam.build();
	acam.query(m);

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
1 8
AABAA
   AABAA
*/