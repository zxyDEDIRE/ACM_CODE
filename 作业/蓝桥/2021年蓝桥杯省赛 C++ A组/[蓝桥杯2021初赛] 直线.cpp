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
void solve()
{
	int n,m;
	set<array<double,2>>s;
	n=20,m=21;
	// n=2;m=3;
	ll ans=n+m;
	for(int x1=1;x1<=n;x1++){
		for(int y1=1;y1<=m;y1++){
			for(int x2=1;x2<=n;x2++){
				for(int y2=1;y2<=m;y2++){
					if(x1==x2||y1==y2)continue;
					double k=1.0*(y2-y1)/(x2-x1);
					double b = (double)(y1*(x2-x1) - x1*(y2-y1)) / (x2 - x1);
					s.insert({k,b});
					// cout<<k<<" "<<b<<endl;
				}
			}
		}
	}
	ans+=(int)s.size();
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
/*
y=kx+b;
b=y-k*x;
*/