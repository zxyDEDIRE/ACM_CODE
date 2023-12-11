/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis;
int G[maxn][5];
int n;
void dfs(int x,int fa)
{
	int cnt=0,i=0,fl=0;
	while(1)
	{
		if(!fl&&v[x][i]==fa){
			G[x][cnt++]=v[x][i];
		}
		else if(fl){
			G[x][cnt++]=v[x][i];
		}
		i=(i+1)%4;
		if(cnt==4)break;
	}
	for(auto i:)
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++){
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	for(auto i:v[1])
		if(i!=0){
			vis[i]=1;
			dfs(i,1);
		}

}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}