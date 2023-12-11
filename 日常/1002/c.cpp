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
bitset<maxn>vis;
vector<int>v;
string str;
int step[100];
map<char,char>mp;
int p[100];
int n,m,flag;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void dfs(int x)
{
	if(flag)return ;
	if(x==m)
	{
		if(step[m-1]==v[0])return ;
		for(int i=0;i<m;i++)
			p[i]=i;
		for(int i=0;i<m;i++)
			p[v[i]]=step[i];
		int cnt=0;
		for(int i=0;i<m;i++)
			if(p[i]==i)
				cnt++;
		if(cnt!=1)return ;



		flag=1;
		
		for(int i=0;i<m;i++)
		{
			//cout<<((char)(v[i]+'a'))<<("|")<<(char)(step[i]+'a')<<"aa"<<endl;
			mp[(char)(v[i]+'a')]=(char)(step[i]+'a');
		}
		return ;
	}
	for(int i=0;i<26;i++)
	{
		if(vis[i])continue;
		if(i==v[x])continue;
		step[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>str;
	vis.reset();
	mp.clear();
	v.clear();
	for(int i=0;i<n;i++)
	{
		int x=str[i]-'a';
		if(!vis[x])
		{
			v.push_back(x);
			vis[x]=1;
		}
	}
	vis.reset();
	m=v.size();
	flag=0;
	dfs(0);
	for(int i=0;i<n;i++)
		cout<<mp[str[i]];
	cout<<endl;
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
/*
1
26
abcdefghijklmnopqrstuvwxzy
*/