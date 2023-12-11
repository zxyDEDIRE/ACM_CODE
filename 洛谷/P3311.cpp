/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[1201][150000];
string nn;
int n,m,ans;
struct Trie{
	int nxt[maxn][26],fail[maxn];
	int val[maxn];
	int cnt[maxn];
	int id[maxn];
	int q[maxn];
	int root=0,indx=0;
	int top=0,low=1;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=q[i]=fail[i]=0;
			for(int j=0;j<10;j++)
				nxt[i][j]=0;
		}
		indx=top=0;low=1;//v.clear();
	}
	void insert(string& str,int x)
	{
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'0';
			if(!nxt[rt][tmp])nxt[rt][tmp]=++indx;
			rt=nxt[rt][tmp];
		}
		val[rt]++;id[x]=rt;
	}
	void build()
	{
		for(int i=0;i<10;i++)
			if(nxt[0][i])
				q[++top]=nxt[0][i];
		while(low<=top){
			int x=q[low++];
			for(int i=0;i<10;i++){
				int &rt=nxt[x][i];
				if(!rt)rt=nxt[fail[x]][i];
				else{
					fail[rt]=nxt[fail[x]][i];
					q[++top]=rt;
				}
			}
		}
	}
	void DP()
	{
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		for(int j=0;j<=indx;j++)
		for(int k=0;k<=9;k++)
			if(!val[nxt[j][k]])
				(dp[i][nxt[j][k]]+=dp[i-1][j])%=mod;
	}
}trie;
void solve()
{
	cin>>nn>>m;
	n=nn.size();
	for(int i=nn.size()-1;i>=0;i--)
	{
		ans=ans*10+(nn[i]-'0');
		ans%=mod;
	}
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		trie.insert(str,i);
	}
	trie.build();
	trie.DP();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}