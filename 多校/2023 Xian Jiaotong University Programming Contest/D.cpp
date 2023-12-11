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
pii p[maxn];
set<pii>s;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
		s.insert(p[i]);
	}
	if(!s.count({0,0})){
		cout<<-1<<endl;
		return ;
	}
	int x_mi=p[1].first;
	int x_ma=p[1].first;
	int y_mi=p[1].second;
	int y_ma=p[1].second;
	for(int i=1;i<=n;i++)
	{
		x_mi=min(x_mi,p[i].first);
		x_ma=max(x_ma,p[i].first);
		y_mi=min(y_mi,p[i].second);
		y_ma=max(y_ma,p[i].second);
	}
	for(int i=x_mi;i<=x_ma;i++)
		for(int j=y_mi;j<=y_ma;j++)
			if(!s.count({i,j})){
				cout<<-1<<endl;
				return ;
			}
	cout<<x_ma-x_mi+y_ma-y_mi<<endl;
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