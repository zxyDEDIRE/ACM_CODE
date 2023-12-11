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
void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
{
	ext[0]=0;
	for(int i=1,p0=0,p=0;i<=lens;i++)
	{
		ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
		while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
		if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
	}
}
string str;
int nxt[maxn];
int dp[maxn];
char s[maxn];
int f[maxn];
int n;
int find(int x,int len){
	if(x>=n||nxt[x]>=len)retur n x;
	return f[x]=find(f[x],len);
}
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
		s[i]=str[i-1];
	for(int i=1;i<=n;i++)
		if(nxt[i]>i)nxt[i]=i;
	exkmp(s,n,s,n,nxt,nxt);
	for(int i=0;i<=n;i++)
	{
		f[i]=i+1;
		dp[i]=INF;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		int x=i,ans=dp[i];
		while(1)
		{
			int k=find(x,i);
			if(k<n)
			{
				ans+=k-x;
				x=k+i;
				ans++;
				dp[x]=min(dp[x],ans+1);
			}
			else break;
		}
	}
	dp[n]=min(dp[n],dp[n-1]+1);
	cout<<dp[n]-1<<endl;
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