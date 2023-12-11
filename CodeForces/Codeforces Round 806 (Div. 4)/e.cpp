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
const int maxn=111;
char mp[maxn][maxn];
char t[maxn][maxn];
int p[maxn][maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='1')p[i][j]=1;
			else p[i][j]=0;
		}
	for(int ii=1;ii<=3;ii++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//t[i][j]=mp[i][n-j+1];
				t[i][j]=mp[n-j+1][i];
			}
		}
		//cout<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[i][j]=t[i][j];
				if(mp[i][j]=='1')p[i][j]++;
				//cout<<mp[i][j];
			}
			//cout<<endl;
		}
	}
	int ans=0;
	//cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//cout<<p[i][j]<<" ";
			ans+=min(abs(0-p[i][j]),abs(4-p[i][j]));
		}
		//cout<<endl;
	}
	cout<<ans/4<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
2 2


*/