/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=20;
int a[N][N];
string str;
int n;
void solve()
{
	// cin>>n>>str;
	memset(a,0,sizeof(a));
	str=" "+str;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(str[j]=='1')
			{
				a[i][i]++;
				a[j][j]++;
				a[i][j]--;
				a[j][i]--;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>str)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}