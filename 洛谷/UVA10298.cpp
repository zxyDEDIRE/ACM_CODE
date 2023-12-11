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
const int maxn=1e6;
int nxt[maxn];
string s;
int n;
void get_nxt()
{
	nxt[1]=0;
	for(int i=2;i<=n;i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[nxt[i]+1]!=s[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
	int now=n;
	vector<int>v;
	while(now){
		now=nxt[now];
		v.push_back(n-now);
	}
	int len=v[0];
	int flag=1;
	for(int i=1;i<v.size();i++)
		if(v[i]-v[i-1]!=len)
			flag=0;
	if(flag)cout<<v.size()<<endl;
	else cout<<1<<endl;
}
void solve()
{
	while(cin>>s&&s!=".")
	{
		n=s.size();
		s=" "+s;
		get_nxt();
		// for(int i=1;i<=n;i++)
		// 	cout<<nxt[i]<<" ";cout<<endl;
	}
}
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