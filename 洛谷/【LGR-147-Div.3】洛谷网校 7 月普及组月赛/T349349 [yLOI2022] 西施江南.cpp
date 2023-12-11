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
set<int>s;
int n;
ll gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
ll lcm(int a,int b){
	ll ans=1ll*a*b/gcd(a,b);
	return ans;
}
void solve()
{
	cin>>n;
	s.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i];
	if(n==2)
	{
		ll a=p[1]*p[2];
		ll b=lcm(p[1],p[2])*gcd(p[1],p[2]);
		if(a==b)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int m=p[i];
		vector<int>v;
		for(int j=2;j*j<=m;j++)
			if(m%j==0){
				v.push_back(j);
				while(m%j==0)
					m/=j;
			}
		if(m!=1)
			v.push_back(m);
		for(auto j:v)
			if(s.count(j)){
				cout<<"No"<<endl;
				return ;
			}
			else s.insert(j);
	}
	cout<<"Yes"<<endl;
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
[2,2]
[2,5]

[2]
[5]

[3,5]
[3]


[2,2]
[2]
[2]

[2,2]
[2]
*/