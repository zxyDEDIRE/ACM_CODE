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
bitset<maxn>vis;
string s[maxn];
vector<string>t;
int n,m,sum=0,flag=0;
void dfs(int x,string str,int yu)
{
	if(flag)return ;
	if(str.size()>16)return ;
	if(x==n-1)
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])
				str+=s[i];
		if(str.size()>16)return ;
		int fl=1;
		for(auto i:t)
			if(str==i)fl=0;
		if(fl)
		{
			flag=1;
			cout<<str<<endl;
		}
		return ;
	}
	if(!yu)return ;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;

		for(int j=1;j<=yu-(n-3-x);j++)
		{
			if(str.size()+j>16)continue;
			string ans=str;
			ans+=s[i];
			for(int ii=1;ii<=j;ii++)
				ans+='_';
			vis[i]=1;
			dfs(x+1,ans,yu-j);
			vis[i]=0;
		}
	}
}
void solve()
{
	cin>>n>>m;
	sum=0;
	for(int i=1;i<=n;i++)
		cin>>s[i],sum+=s[i].size();
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		if(str.size()>=sum+(n-1))t.push_back(str);
	}

	if(sum+n-1>16)
	{
		cout<<-1<<endl;
		return ;
	}
	if(n==1)
	{
		int fl=0;
		for(auto i:t)
			if(s[1]==i)fl=1;
		if(!fl) cout<<s[1]<<endl;
		else cout<<-1<<endl;
		return ;
	}
	sum=16-sum;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum-(n-2);j++)
		{
			string ans=s[i];
			for(int I=1;I<=j;I++)
				ans+='_';
			vis[i]=1;
			dfs(1,ans,sum-j);
			vis[i]=0;
		}
	}
	if(!flag)cout<<-1<<endl;
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
/*
2 2
a
bbbbbbbbbb
a_b
a__b
*/