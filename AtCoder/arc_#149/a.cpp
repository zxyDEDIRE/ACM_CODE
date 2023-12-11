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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<pii>v;
int dp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int x=1;x<10;x++)
	{
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=(dp[i-1]*10+x)%m;
			if(dp[i]==0)
				v.push_back({x,i});
		}
	}
	sort(v.begin(),v.end(),[&](pii a,pii b){
		if(a.second!=b.second)return a.second>b.second;
		else return a.first>b.first;
	});
	if(v.size())
	{
		for(int i=1;i<=v[0].second;i++)
			cout<<v[0].first;
	}
	else cout<<-1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}