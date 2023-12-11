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
	int n;
	std::vector<int> v;
	cin>>n;
	v.resize(n*5);
	for(auto &i:v)
		cin>>i;
	sort(v.begin(),v.end());
	double sum=0;
	for(int i=n;i<n*4;i++){
		sum+=v[i];
		// cout<<v[i]<<endl;
	}
	// cout<<sum<<endl;

	// cout<<1.0*sum/(3*n)<<endl;
	printf("%.8lf",1.0*sum/(3*n));
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
9 8
*/