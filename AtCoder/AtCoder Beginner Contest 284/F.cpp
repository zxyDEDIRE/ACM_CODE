/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
char s1[maxn];
char s2[maxn];
char t1[maxn];
char t2[maxn];
int len;
int n;
void init(char *s,int *nxt)
{
	nxt[1]=0;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}
int kmp(char *s,char *t,int *nxt)
{
	int m=0;
	for(int i=0,j=0;i<n;i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=nxt[j];
		if(t[j+1]==s[i+1])j++;
		m=j;
	}
	return m;
}
void solve()
{
	cin>>n;
	len=n;
	for(int i=1;i<=n;i++)
		cin>>s1[i],s2[n-i+1]=s1[i];
	for(int i=1;i<=n;i++)
		cin>>t1[i],t2[n-i+1]=t1[i];

	init(s1,nxt);

	int ans=kmp(t2,s1,nxt);
	if(ans==0){
		cout<<-1<<endl;
		return ;
	}
	int flag=1;
	int r=n;
	for(int i=ans+1;i<=n;i++,r--)
	{
		if(s1[i]!=t1[r])
		{
			flag=0;
		}
	}
	if(flag==0){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=ans;i++)
		cout<<s1[i];
	for(int i=ans+1;i<=n;i++)
		cout<<t1[i];
	cout<<endl;
	cout<<ans<<endl;
}
/*
4
a dcb 	a bcd
adcbabcd
*/
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
