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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	multiset<int>s;
	int n;cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x%2==1&&x>1)x--;
		s.insert(x);
		sum+=x;
	}
	while(1)
	{
		int x=*s.begin();
		int y=*s.rbegin();
		if(x*2+floor(y/2)<x+y)
		{
			cout<<x<<" "<<y<<endl;
			cout<<x*2<<" "<<floor(y/2)<<endl<<endl;
			s.erase(s.find(x));
			s.erase(s.find(y));
			sum=sum-(x+y)+(x*2+floor(y/2));
			s.insert(x*2);
			s.insert(floor(y/2));
		}
		else break;
	}
	cout<<sum<<endl;
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