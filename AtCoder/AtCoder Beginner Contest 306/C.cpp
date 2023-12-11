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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
pii p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*3;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		p[i].first=i;
		sort(v[i].begin(),v[i].end());
		p[i].second=v[i][1];
	}
	sort(p+1,p+1+n,[&](pii a,pii b){
		return a.second<b.second;
	});
	for(int i=1;i<=n;i++)
		cout<<p[i].first<<" ";

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