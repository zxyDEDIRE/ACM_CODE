/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6;
int nxt[maxn];
int s[maxn];
int t[maxn];
int n,m,k;
void get_nxt()
{
	nxt[1]=0;
	for(int i=2;i<=m;i++)
	{
		nxt[i]=nxt[i-1];
		if(nxt[i]&&t[i]!=t[nxt[i]+1])
			nxt[i]=nxt[nxt[i]];
		if(t[nxt[i]+1]==t[i])nxt[i]++;
	}
}
void kmp()
{
	get_nxt();
	int cnt=0;
	for(int i=0,j=0;i<n;i++)
	{
		while(j>0&&(t[j+1]+s[i+1])%k!=0)j=nxt[j];
		if((t[j+1]+s[i+1])%k==0)j++;
		if(j==m)
		{
			j=nxt[j];
            cnt++;
		}
	}
	cout<<cnt<<endl;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		nxt[i]=0;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=m;i++)
		cin>>t[i];
	for(int i=1;i<n;i++)
	{
		s[i]=s[i+1]-s[i];
		s[i]%=k;
		s[i]=(s[i]+k)%k;
	}
	for(int i=1;i<m;i++)
	{
		t[i]=t[i+1]-t[i];
		t[i]%=k;
		t[i]=(t[i]+k)%k;
	}
	n--;
	m--;
	kmp();
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
5 2 2
1 3 2 3 0
1 3
*/