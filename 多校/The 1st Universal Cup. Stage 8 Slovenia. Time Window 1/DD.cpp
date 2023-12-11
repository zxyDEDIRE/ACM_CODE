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
int w,ans;
int dfs()
{
	int len,n;
	cin>>len>>n;
	vector<int>v;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x=dfs();
		v.push_back(x);
		sum+=x;
	}
	sort(v.begin(),v.end());
	int r=v.size()-1;
	while(sum>w)
	{
		ans++;
		sum-=v[r];
		r--;
	}
	len+=sum;
	ans+=len/w;
	return len%w;
}
void solve()
{
	cin>>w;
	int x=dfs();
	if(x)ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}