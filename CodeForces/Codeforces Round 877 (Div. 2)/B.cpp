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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		p[x]=i;
	}
	if(p[n]<min(p[1],p[2]))
		cout<<p[n]<<" "<<min(p[1],p[2])<<endl;
	else if(p[n]>max(p[1],p[2]))
		cout<<p[n]<<" "<<max(p[1],p[2])<<endl;
	else cout<<p[1]<<" "<<p[2]<<endl;

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
8
3
1 2 3
3
1 3 2
5
1 3 2 5 4
6
4 5 6 1 2 3
9
8 7 6 3 2 1 4 5 9
10
7 10 5 1 9 8 3 2 6 4
10
8 5 10 9 2 1 3 4 6 7
10
2 3 5 7 10 1 8 6 4 9

*/