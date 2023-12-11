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
const int maxn=1e6;
int nxt[maxn];
string s,t;
int n,m;
void get_num(string &t)
{
	nxt[1]=0;
	for(int i=2;i<t.size();i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&t[i]!=t[nxt[i]+1])
			nxt[i]=nxt[nxt[i]];
		if(t[nxt[i]+1]==t[i])nxt[i]++;
	}
}
void kmp(string &s,string &t)
{
	int ans=0;
	int x=0;
	for(int i=0,j=0;i<s.size();i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=nxt[j];
		if(t[j+1]==s[i+1])j++;
		if(j==t.size()-1)
		{
			j=nxt[j];
			int l=i-(t.size()-1)+2;
			int r=l+t.size()-1;
			int cnt=0;
			cnt+=(l-x)*(s.size()-r+1);
			//cout<<l<<" "<<l-x<<" "<<s.size()-r+1<<" "<<cnt<<endl;
			ans+=cnt;
			x=l;
		}
	}
	cout<<ans<<endl;
}
/*
abaaa ab aba
*/
void solve()
{
	cin>>n>>m>>s>>t;
	s=" "+s;
	t=" "+t;
	get_num(t);
	kmp(s,t);
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