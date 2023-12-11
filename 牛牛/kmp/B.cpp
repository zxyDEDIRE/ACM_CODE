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
const int maxn=2e6+10;
const int mod=998244353;
string s[maxn];
int nxt[maxn];
int n;
void get_nxt(string &s)
{
	nxt[1]=0;
	for(int i=2;i<s.size();i++){
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[i]!=s[nxt[i]+1])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}
ll kmp(string &s,string &t)
{
	ll cnt=0;
	for(int i=0,j=0;i<s.size();i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=nxt[j];
		if(t[j+1]==s[i+1])j++;
		if(j==t.size()-1)
		{
			j=nxt[j];
            cnt++;
		}
	}
	return cnt;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=" "+s[i];
	}
	int t=1,flag=1;
	for(int i=1;i<=n;i++)
		if(s[i].size()<s[t].size())
			t=i;
	for(int i=1;i<=n;i++)
		if((s[i].size()==s[t].size())&&s[i]!=s[t])flag=0;
	if(flag)
	{
		get_nxt(s[t]);
		ll ans=1;
		for(int i=1;i<=n;i++)
			ans=(1ll*ans*kmp(s[i],s[t]))%mod;
		for(int i=1;i<=n;i++)
			if(s[i].size()==s[t].size())
				cout<<ans%mod<<endl;
			else cout<<0<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
			cout<<0<<endl;
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/