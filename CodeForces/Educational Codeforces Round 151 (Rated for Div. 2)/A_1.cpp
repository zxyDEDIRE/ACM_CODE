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
	int n,k,x;
	cin>>n>>k>>x;
	if(x!=1){
		cout<<"YES"<<endl;
		cout<<n<<endl;
		while(n--)cout<<1<<" ";
		cout<<endl;
	}
	else if(k==1){cout<<"NO"<<endl;}
	else if(k==2){
		if(n==1||n&1){cout<<"NO"<<endl;return ;}
		cout<<"YES"<<endl;
		int cnt=0;
		while(n)n-=2,cnt++;
		cout<<cnt<<endl;
		while(cnt)cout<<2<<" ",cnt--;
		cout<<endl;
	}
	else if(k==3)
	{
		if(n<=1){cout<<"NO"<<endl;return ;}
		cout<<"YES"<<endl;
		vector<int>v;
		int yu=(n%2);
		n-=yu;
		while(n){
			v.push_back(2);
			n-=2;
		}
		if(yu)v.back()++;
		cout<<v.size()<<endl;
		for(auto i:v)
			cout<<i<<" ";cout<<endl;
	}
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