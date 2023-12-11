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
const int maxn=1e6+10;
const int mod=1000000007;
vector<int>v[maxn];
int nxt[maxn];
int num[maxn];
int p[maxn];
void get_nxt(string &t)
{
	
}
int find(int x,int fa)
{
	if(x*2<=fa)return num[x];
	else return find(p[x],fa);
}
void solve()
{
	string s;
	cin>>s;
	s=" "+s;
	nxt[1]=0;
	num[1]=1;
	for(int i=2;i<s.size();i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[nxt[i]+1]!=s[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
		num[i]=num[nxt[i]]+1;
	}
	int n=s.size()-1;
	ll ans=1;
	for(int i=2,j=0;i<s.size();i++)
	{
		while(j&&s[i]!=s[j+1])
			j=nxt[j];
		if(s[i]==s[j+1])
			j++;
		while((j*2)>i)
			j=nxt[j];
		ans=(ans*(num[j]+1))%mod;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
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
abcababc
*/