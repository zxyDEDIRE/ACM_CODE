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
void get_next(string &s)
{
	nxt[1]=0;
	for(int i=2;i<s.size();i++){
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[i]!=s[nxt[i]+1])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}
void kmp(string &s,string &t)
{
	for(int i=0,j=0;i<s.size();i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=nxt[j];
		if(t[j+1]==s[i+1])j++;
		if(j==t.size()-1)
		{
			j=nxt[j];
            cout<<i-(t.size()-1)+2<<endl;
		}
	}
}
void solve()
{
	string s,t;
	cin>>s;
	cin>>t;
	s=" "+s;
	t=" "+t;
	get_next(t);
	kmp(s,t);
	for(int i=1;i<t.size();i++)
		cout<<nxt[i]<<" ";cout<<endl;
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
CEBDAEEAACEBDAE
EBDAE

*/