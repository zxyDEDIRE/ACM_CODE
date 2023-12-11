/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
int in[maxn];
int n,ans;
int c(int x,int y)
{
	if(x<=0)return 0;
	int ans=1;
	for(int i=1;i<=y;i++)
		ans*=x,x--;
	for(int i=1;i<=y;i++)
		ans/=i;
	return ans;
}
void get(int x)
{
	vector<int>p;
	int head=0,hand=0;
	int tot=0;
	for(auto y:v[x])
	{
		if(in[y]==1)head++;
		else if(in[y]==2)hand++;
		else p.push_back(in[y]-1),tot+=c(in[y]-1,2);
	}
	ans+=head*c(hand,2)*p.size()*tot;
	ans+=c(hand,1)*c(hand-2,2);
}
void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
		in[i]=0,v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	for(int i=1;i<=n;i++)
		get(i);
	cout<<ans<<endl;
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
1
16
1 3
2 3
5 6
5 7
8 16
9 16
11 15
10 15
13 14
12 14
3 4
5 4
16 4
15 4
14 4

1
13
2 4
3 4
1 4
5 7
6 7
7 1
8 10
9 10
1 10
11 13
12 13
1 13
*/