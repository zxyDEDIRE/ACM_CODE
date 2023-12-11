/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int mod=1e4+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
int n,m,ans=1;
struct Trie{
	int dp[222][11111];
	int nxt[maxn][26],fail[maxn];
	int val[maxn];
	int q[maxn];
	int root=0,indx=0;
	int top=0,low=1;
	void insert(string& str,int x)
	{
		int rt=0;
		for(int i=0;i<str.size();i++)
		{
			int tmp=str[i]-'A';
			if(!nxt[rt][tmp])nxt[rt][tmp]=++indx;
			rt=nxt[rt][tmp];
		}
		val[rt]=1;
	}
	void build()
	{
		for(int i=0;i<26;i++)
			if(nxt[0][i])
				q[++top]=nxt[0][i];
		while(low<=top)
		{
			int x=q[low++];
			for(int i=0;i<26;i++)
			{
				int &rt=nxt[x][i];
				if(!rt)rt=nxt[fail[x]][i];
				else
				{
					val[fail[rt]]|=val[nxt[fail[x]][i]];
					fail[rt]=nxt[fail[x]][i];
					q[++top]=rt;
				}
			}
		}
	}
	void DP()
	{
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
			for(int j=0;j<=indx;j++)
				for(int k=0;k<26;k++)
					if(!val[nxt[j][k]])
					(dp[i][nxt[j][k]]+=dp[i-1][j])%=mod;
		for(int i=1;i<=m;i++)
			ans=(ans*26)%mod;
		for(int i=0;i<=indx;i++)
			ans=(ans-dp[m][i]+mod+mod)%mod;
		cout<<ans<<endl;
	}
}trie;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		trie.insert(str,i);
	}
	trie.build();
	trie.DP();
}
signed main(){
  //freopen("C:\\Users\\tob\\Desktop\\P3796_1.in.txt","r",stdin);
  //freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
  //fclose(stdin);
  //fclose(stdout);
	return 0;
}