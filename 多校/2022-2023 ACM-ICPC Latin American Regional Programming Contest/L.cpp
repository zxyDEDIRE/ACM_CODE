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
vector<ll>v;
ll n,p,h,H;
bool ok()//0 L 1 R
{
	ll x=1,y=p;
	ll t=(1ll<<(n-1));
	ll s=1;
	for(auto i:v)
	{
		// cout<<x<<" "<<y<<" "<<i<<endl;
		if(i==0)
		{
			if(y<=t)
			{
				x=s+(s-x+1);
				y=t-x+1;
			}
			else
			{
				y=y-t;
			}
		}
		else
		{
			if(y<=t);
			else
			{
				x=s+(s-x+1);
				y=t-(y-t)+1;
			}
		}
		t/=2;
		s*=2;
		// cout<<x<<" "<<y<<endl;
	}
	// cout<<"ans "<<x<<" "<<h<<endl;
	return x==H;
}
void solve()
{
	cin>>n>>p>>h;
	H=h;
	for(int i=n-1;i>=0;i--)
	{
		ll t=(1ll<<i);
		// cout<<h<<" "<<t<<endl;
		if(h>t)v.push_back(1),h=t*2-h+1;
		else v.push_back(0);
	}
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	reverse(v.begin(),v.end());
	int flag=0;
	if(!ok())flag=1;

	for(auto i:v)
		if(flag==0)
		{
			if(i==0)cout<<'L' ;
			else cout<<"R";
		}
		else
		{
			if(i==1)cout<<'L';
			else cout<<"R";
		}
		
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
7 2 2 1
16 1 1 

7 4 1

1 2 3 4 5 6 7 8
R
8 7 6 5
1 2 3 4

1 16 (1 16)
1 8(2,8)

*/