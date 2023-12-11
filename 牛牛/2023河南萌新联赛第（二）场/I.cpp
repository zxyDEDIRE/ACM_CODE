/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n;
void solve()
{
	vector<int>p;
	cin>>n;
	int m=n;
	int cnt=log2(n)+1;
	while(m){
		p.push_back(m%2);
		m>>=1;
	}
	// for(auto i:p)
	// 	cout<<i<<" ";cout<<endl;
	for(int i=(int)(p.size()-2);i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(cnt==0)break;
			if(p[i]==1&&p[j]==0)
			{
				cnt--;
				swap(p[i],p[j]);
				break;
			}
		}
	}
	// for(auto i:p)
	// 	cout<<i<<" ";cout<<endl;
	int ans=0;
	for(int i=0;i<(int)(p.size());i++)
	{
		if(p[i])
			ans+=(1<<i);
	}
	cout<<n-ans<<endl;
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