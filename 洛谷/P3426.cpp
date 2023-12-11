/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int nxt[maxn];
char s[maxn];
void get_nxt(char *s)
{
	int len=strlen(s+1);
	nxt[1]=0;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[nxt[i]+1]!=s[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])
			nxt[i]++;
	}
}
int dp[maxn];
int t[maxn];
void solve()
{
	scanf("%s",s+1);
	get_nxt(s);
	int n=strlen(s+1);
	// for(int i=1;i<=n;i++)
	// {
	// 	printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
	// 	for(int j=1;j<=i;j++)
	// 		cout<<s[j];
	// 	cout<<endl;
	// }
	dp[1]=t[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=i;
		if(t[dp[nxt[i]]]>=i-nxt[i])
			dp[i]=dp[nxt[i]];
		t[dp[i]]=i;
	}
	cout<<dp[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
ababbababbabababbabababbababbaba
ababbaba
	 ababbaba
*/