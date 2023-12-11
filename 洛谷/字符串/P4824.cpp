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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e7;
stack<int>st;
bool vis[maxn];
int nxt[maxn];
int p[maxn];
string s,t;
void get_nxt(string &str)
{
	nxt[1]=0;
	for(int i=2;i<str.size();i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&str[nxt[i]+1]!=str[i])
			nxt[i]=nxt[nxt[i]];
		if(str[nxt[i]+1]==str[i])
			nxt[i]++;
	}
}
void solve()
{
	cin>>s>>t;
	s=" "+s;
	t=" "+t;
	get_nxt(t);
	st.push(0);
	for(int i=0,j=0;i<s.size();i++)
	{
		while(j&&s[i+1]!=t[j+1])
			j=nxt[j];
		if(s[i+1]==t[j+1])j++;
		st.push(j);
		p[i]=j;
		if(j==t.size()-1)
		{
			vis[i+1]=1;
			int II=t.size()-1;
			while(II--)
				st.pop();
			j=st.top();
		}
	}
	string ans="";
	int cnt=0;
	for(int i=s.size()-1;i>=1;i--)
	{
		if(vis[i])cnt+=t.size()-1;
		if(cnt)
		{
			cnt--;
			continue;
		}
		else ans+=s[i];
	}
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i];
}
/*
abzababcacacaa
abca
*/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
whatthefun
*/
