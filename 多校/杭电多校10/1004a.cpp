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
vector<int>v[maxn];
double p[maxn];
int n;
void solve()
{
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int tot=1000;
	while(tot--)
	{
		for(int i=1;i<=n;i++)
		{
			double sum=p[i];
			int cnt=1;
			for(auto y:v[i])
				sum+=p[y],cnt++;
			p[i]=1.0*sum/cnt;
			// for(auto y:v[i])
			// 	p[y]=p[i];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
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
【管理员】116支队伍的比赛打了105的废物罢了 16:48:08
4 4 
1 2 3 4
1 2 
2 3
3 4
4 1

【管理员】116支队伍的比赛打了105的废物罢了 16:48:13
4 5
1 2 3 4
1 2 
2 3
3 4
4 1
2 4


*/