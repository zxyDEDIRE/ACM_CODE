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
int a[maxn],b[maxn];
int s[maxn],t[maxn];
int nxt[maxn];
int n,m;
void get_nxt()
{
	nxt[1]=0;
	for(int i=2;i<=m;i++)
	{
		nxt[i]=nxt[i-1];
		if(t[nxt[i]+1]!=t[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(t[nxt[i]+1]==t[i])nxt[i]++;
	}
}
void kmp()
{
	int ans=0;
	for(int i=0,j=0;i<n;i++)
	{
		while(j>0&&t[j+1]!=s[i+1])
			j=nxt[j];
		if(t[j+1]==s[i+1])
			j++;
		if(j==m)
		{
			j=nxt[j];
			ans++;
		}
	}
	cout<<ans<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)s[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(i>1)t[i-1]=b[i]-b[i-1];
	}
	n--;
	m--;
	// for(int i=1;i<=n;i++)
	// 	cout<<s[i]<<" ";cout<<endl;
	// for(int i=1;i<=m;i++)
	// 	cout<<t[i]<<" ";cout<<endl;
	if(m==0){
		cout<<n+1<<endl;
		return ;
	}
	get_nxt();
	kmp();
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
/*
10 5
5 10 8 10 11 9 11 12 10 15
4 2 4 5 3
*/