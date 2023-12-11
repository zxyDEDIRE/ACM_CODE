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
char mp[100][100];
int n=8;
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	char ans='.';
	for(int i=1;i<=n;i++)
	{
		if(mp[i][1]!='.')
		{
			int fl=1;
			for(int j=1;j<=n;j++)
				if(mp[i][j]!=mp[i][1])
					fl=0;
			if(fl)ans=mp[i][1];
		}
	}
	if(ans!='.')
	{
		cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[1][i]!='.')
		{
			int fl=1;
			for(int j=1;j<=n;j++)
				if(mp[j][i]!=mp[1][i])
					fl=0;
			if(fl)ans=mp[1][i];
		}
	}
	cout<<ans<<endl;
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