/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
map<int,int>mp;
int n,m,x;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear();
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			v[i].push_back(x);
			mp[x]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(auto j:v[i])
		{
			if(mp[j]==1)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			cout<<"YES"<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
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
1001
0110
1100
0011
1 3
2 3
2 4
1 4
*/