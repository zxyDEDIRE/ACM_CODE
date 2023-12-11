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
char mp[1000][1000];
int n,a,b;
void doit(int x)
{
	int fl;
	if(mp[1][x]=='.')fl=1;
	else fl=2;
	int j=1;
	j++;
	if(j>a)
	{
		j=1;
		if(fl==1)fl=2;
		else fl=1;
	}

	for(int i=2;i<=n*a;i++)
	{
		if(fl==1)mp[i][x]='.';
		else mp[i][x]='#';

		j++;
		if(j>a)
		{
			j=1;
			if(fl==1)fl=2;
			else fl=1;
		}
	}
}
void solve()
{
	cin>>n>>a>>b;
	for(int i=1,j=1,fl=1;i<=n*b;i++)
	{
		if(fl==1)mp[1][i]='.';
		else mp[1][i]='#';
		j++;
		if(j>b)
		{
			j=1;
			if(fl==1)fl=2;
			else fl=1;
		}
		doit(i);
	}
	for(int i=1;i<=n*a;i++)
	{
		for(int j=1;j<=n*b;j++)
			cout<<mp[i][j];
		cout<<endl;
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