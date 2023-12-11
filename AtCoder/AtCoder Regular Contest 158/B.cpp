/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
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
vector<double>v;
double ma=-INF; 
double mi=INF;
int n;
double f(int x,int y,int z){
	return 1.0*(v[x]+v[y]+v[z])/(v[x]*v[y]*v[z]);
}
void solve()
{
	
	cin>>n;
	ma=-INF;
	mi=INF; 
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=2;i<v.size();i++){
		ma=max(ma,f(i,i-1,i-2));
		mi=min(mi,f(i,i-1,i-2));
	}
	ma=max(ma,f(0,1,n-1));
	ma=max(ma,f(0,n-2,n-1));
	mi=min(mi,f(0,1,n-1));
	mi=min(mi,f(0,n-2,n-1));
	printf("%.14lf\n",mi);
	printf("%.14lf\n",ma);

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