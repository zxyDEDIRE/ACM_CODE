/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
vector<int>v;
int a[maxn];
int n,l,r,x,ans;
bool ok()
{
	if(v.size()<2)return 0;
	int ma=*max_element(v.begin(),v.end());
	int mi=*min_element(v.begin(),v.end());
	int sum=accumulate(v.begin(),v.end(),0);
	if(ma-mi<x||sum<l||sum>r)return 0;
	return 1;
}
void dfs(int x)
{
	if(ok())ans++;
	if(x>n)return ;
	for(int i=x;i<=n;i++)
	{
		v.push_back(a[i]);
		dfs(i+1);
		v.pop_back();
	}
}
void solve()
{
	cin>>n>>l>>r>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}