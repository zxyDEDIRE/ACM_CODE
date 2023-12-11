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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
int nxt[maxn];
string s;
int n;
void get_nxt(string &t)
{
	nxt[1]=0;
	for(int i=2;i<s.size();i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]&&t[nxt[i]+1]!=t[i])
			nxt[i]=nxt[nxt[i]];
		if(t[nxt[i]+1]==t[i])nxt[i]++;
	}
}
int get_len()
{
	if(nxt[n]==0)return n;
	if(n==1)return 1;
	for(int i=n-1;i>=1;i--)
	{
		if(nxt[i]==nxt[i+1]-1&&nxt[i]);
		else return i;
	}
	return 0;
}
void solve()
{
	cin>>n>>s;
	s=" "+s;
	get_nxt(s);
	int len=get_len();
	int ans=0;
	for(int i=2,j=2;i<=n;i++)
	{
		j=i;
		while(nxt[j])j=nxt[j];
		if(nxt[i]!=0)nxt[i]=j;
		ans+=i-j;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
2
3
2
5
2
7
4

b 1 1
ba 2 3
bab 3 6
baba 2 8
babab 5 13
bababa 2 15
bababab 7 22
babababa 4 26
*/