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
void solve()
{
	int n,x;
	vector<int>a,b;
	vector<int>dp;
	vector<int>p;

	cin>>n>>x;
	a.resize(n);
	b.resize(n);
	dp.resize(x+10);

	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		int cnt=1;
		while(b[i]>=cnt){
			p.push_back(a[i]*cnt);
			b[i]-=cnt;
			cnt*=2;
		}
		if(b[i])
			p.push_back(b[i]*a[i]);
	}
	dp[0]=1;
	// sort(p.begin(),p.end());
	// for(auto i:p)
	// 	cout<<i<<" ";
	// cout<<endl;

	for(auto i:p)
	{
		for(int j=x;j>=1;j--)
			if(j>=i)
				dp[j]|=dp[j-i];
	}


	cout<<(dp[x]==1?"Yes":"No")<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}