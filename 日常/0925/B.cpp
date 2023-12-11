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
int p[100];
int a[100];
int vis[100];
int ok[100];
int n,k,ma;
void dfs(int step)
{
	if(step==k+1)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])a[i]=a[i-1];
			else a[i]=p[i];
		}
		int ans=0;
		for(int i=2;i<=n;i++)
			ans+=(a[i]-a[i-1])*(a[i]-a[i-1]);
		if(ans>ma)
		{
			ma=ans;
			for(int i=1;i<=n;i++)
				ok[i]=vis[i];
		}
	}
	for(int i=2;i<n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(step+1);
		vis[i]=0;
	}
}
void solve(int it)
{
	k=it;
	ma=0;
	dfs(1);
	cout<<ma<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<ok[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<=n-2;i++)
		solve(i);
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10
1 5 6 7 7 7 7 9 11 13
0 1 1 1 1 1 0 1 0  0
*/