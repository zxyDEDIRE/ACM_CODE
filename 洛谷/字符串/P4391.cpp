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
int nxt[maxn];
string s;
int n;
void get_nxt(string t)
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
void solve()
{
	cin>>n>>s;
	s=" "+s;
	get_nxt(s);
	cout<<n-nxt[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
30
aaaaaaaaabaaaaaaaaabaaaaaaaaab
*/