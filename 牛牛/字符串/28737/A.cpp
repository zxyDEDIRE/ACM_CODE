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
const int maxn=1e6;
vector<int>v;
int nxt[maxn][30];
int val[maxn];
int n,indx;
void insert(string &s,int x)
{
	int rt=0;
	int flag=0;
	for(int i=0;i<s.size();i++)
	{
		int tmp=s[i]-'a';
		if(!nxt[rt][tmp])
			nxt[rt][tmp]=++indx;
		rt=nxt[rt][tmp];
	}
	val[rt]=x;
}
void dfs(int x)
{
	if(val[x])
	{
		v.push_back(val[x]);
		return ;
	}
	for(int i=0;i<26;i++)
		if(nxt[x][i])
			dfs(nxt[x][i]);
}
string mp[maxn];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		mp[i]=str;
		insert(str,i);
	}
	dfs(0);
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<mp[i]<<endl;
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