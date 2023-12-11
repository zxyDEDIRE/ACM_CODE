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
const int maxn=1e6;
int nxt[maxn];
int dep[maxn];
void get_nxt(string &s)
{
	nxt[1]=0;
	dep[1]=1;
	int len=s.size()-1;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])
			nxt[i]++;
		dep[i]=dep[nxt[i]]+1;
	}
}
void solve()
{
	string str;
	cin>>str;
	str=" "+str;
	get_nxt(str);
	int n=str.size()-1;
	int ans=1;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&str[j+1]!=str[i])
			j=nxt[j];
		if(str[j+1]==str[i])j++;
		while((j*2)>i)
			j=nxt[j];
		ans=(ans*(dep[j]+1))%INF;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}