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
const int maxn=1e6+100;
ll dp[1601][1600][2];
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
		int rt=0,i=0;
		for(;i<str.size();i++){
			int tmp=str[i]-'0';
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
					val[rt]|=val[nxt[rt]];
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
	void query(const string&s)
	{
		int n=s.size();
		// cout<<"n "<<n<<endl;
		for(int i=0;i<s[0]-'0';i++){
			cout<<"I "<<i<<" "<<val[ch[0][i]]<<endl;
			if(!val[ch[0][i]]){
				cout<<"SDF "<<i<<endl;
				dp[1][ch[0][i]][1]=1;
			}
		}
			
		if(!val[ch[0][s[0]-'0']])
			dp[1][ch[0][s[0]-'0']][0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=indx;j++)
			{
				for(int k=0;k<=9;k++)
				{
					if(!val[ch[j][k]])
					{
						dp[i][ch[j][k]][1]+=dp[i-1][j][1];
						if(k==s[i-1]-'0')
						{
							dp[i][ch[j][k]][0]+=dp[i-1][j][0];
						}
						else if(k<s[i-1]-'0')
						{
							dp[i][ch[j][k]][1]+=dp[i-1][j][0];
						}
						dp[i][ch[j][k]][0]%=mod;
						dp[i][ch[j][k]][1]%=mod;
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=indx;i++){
			cout<<dp[n][i][0]<<" "<<dp[n][i][1]<<endl;
			ans+=dp[n][i][0]+dp[n][i][1];
			ans%=mod;
		}
		ans=(ans-1+mod)%mod;
		cout<<ans<<endl;
	}
}acam;
string s,t;
int n,m;
void solve()
{
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		acam.insert(s,i);
	}
	acam.build();
	acam.query(t);

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
2000
1
001
*/