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
const int maxn=3e5+100;
string mp[3];
bool vis[maxn][2];
int n;
void solve()
{
	cin>>n>>mp[0]>>mp[1];
	int flag=0;
	vis[0][0]=1;
	vis[1][0]=1;
	for(int i=1;i<n;i++)
		if(mp[0][i-1]==mp[1][i]&&mp[1][i-1]==mp[0][i]&&mp[0][i]!=mp[1][i])flag=1;
	for(int i=1;i<n-1;i++)
	{
		if(mp[0][i-1]==mp[0][i]&&mp[0][i]==mp[0][i+1]&&mp[1][i]==mp[0][i]&&mp[0][i]=='B'&&mp[1][i-1]==mp[1][i+1]&&mp[1][i-1]=='W')flag=1;
		if(mp[1][i-1]==mp[1][i]&&mp[1][i]==mp[1][i+1]&&mp[0][i]==mp[1][i]&&mp[1][i]=='B'&&mp[0][i-1]==mp[0][i+1]&&mp[0][i-1]=='W')flag=1;
	}
	if(flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
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