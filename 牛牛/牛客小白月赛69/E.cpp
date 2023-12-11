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
pii p[maxn];
int n;
bool ok(pii x,pii y,pii z)
{
	if(x.first!=y.first&&y.first!=z.first&&z.first!=x.first)
	{
		double k1 = 1.0 * (y.second - x.second) / (y.first - x.first);
		double k2 = 1.0 * (z.second - y.second) / (z.first - y.first);
		double k3 = 1.0 * (z.second - x.second) / (z.first - x.first);
		if(k1 == k2 && k2 == k3)
			return 0;
		else 
			return 1;
	}
	else if(x.first == y.first && y.first == z.first)
		return 0;
	else
	{
		if(x.second == y.second && y.second == z.second)
			return 0;
		else
			return 1;
	}
}
int dis(int a,int b){
	auto x=p[a],y=p[b];
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(ok(p[i],p[j],p[k])){
					if(dis(i,j)==dis(j,k)||dis(j,i)==dis(i,k)||dis(i,k)==dis(k,j))
						cnt++;
				}
	cout<<cnt<<endl;
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