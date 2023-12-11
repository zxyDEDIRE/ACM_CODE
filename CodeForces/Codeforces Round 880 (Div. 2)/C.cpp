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
int len_a,len_b,len_c;
pii p[5];
ll k;
void solve()
{
	for(int i=1;i<=3;i++)
	{
		int x;cin>>x;
		p[i].first = pow(10,x-1);
		p[i].second = pow(10,x)-1;
	}
	cin>>k;
	for(int i=p[1].first;i<=p[1].second;i++)
	{
		int l=p[3].first-i;
		int r=p[3].second-i;
		if(r<p[2].first||l>p[2].second)continue;
		l=max(l,p[2].first);
		r=min(r,p[2].second);
		if(k>(r-l+1))k-=(r-l+1);
		else
		{
			l=l+k-1;
			cout<<i<<" + "<<l<<" = "<<i+l<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
10
*/