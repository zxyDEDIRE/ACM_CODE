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
int mp[10][10];
int h[4];
int w[4];
int n=3;
int ans;
bool ok()
{
	mp[1][3]=h[1]-mp[1][1]-mp[1][2];if(mp[1][3]<1)return 0;
	mp[2][3]=h[2]-mp[2][1]-mp[2][2];if(mp[2][3]<1)return 0;
	

	mp[3][1]=w[1]-mp[1][1]-mp[2][1];if(mp[3][1]<1)return 0;
	mp[3][2]=w[2]-mp[1][2]-mp[2][2];if(mp[3][2]<1)return 0;

	int a=h[3]-mp[3][1]-mp[3][2];if(a<1)return 0;
	int b=w[3]-mp[1][3]-mp[2][3];if(b<1)return 0;
	

	if(a!=b)return 0;

	mp[3][3]=a;
	
	return 1;
}
void solve()
{
	for(int i=1;i<=3;i++)
		cin>>h[i];
	for(int i=1;i<=3;i++)
		cin>>w[i];
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			for(int I=1;I<=30;I++)
			{
				for(int J=1;J<=30;J++)
				{
					mp[1][1]=i;
					mp[1][2]=j;
					mp[2][1]=I;
					mp[2][2]=J;
					if(ok())ans++;

					// {
					// 	for(int i=1;i<=n;i++)
					// 	{
					// 		for(int j=1;j<=n;j++)
					// 			cout<<mp[i][j]<<" ";
					// 		cout<<endl;
					// 	}
					// }
					// return ;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}