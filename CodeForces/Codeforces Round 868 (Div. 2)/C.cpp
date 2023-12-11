/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
map<int,int>mp;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;i++){
		cin>>p[i];
		int x=p[i];
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				while(x%j==0)
					mp[j]++,x/=j;
			}
		if(x!=1)mp[x]++;
	}
	// for(auto [x,y]:mp)
	// {
	// 	cout<<x<<" "<<y<<endl;
	// }
	int fl=0;
	int a=0,b=0;
	for(auto [x,y]:mp)
	{
		int now=y/2;
		a+=now;
		if(y&1)b++;
	}
	int now=b/3;
	a+=now;
	cout<<a<<endl;
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
12
2 3 
4 6 12

2 3
c(3,2)


4
4*3/2 = 

2
c(2,2)
*/