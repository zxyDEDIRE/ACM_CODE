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
	int x;
	cin>>x;
	map<int,int>mp;
	mp[x]=0;
	for(int i=1,op;i<=999;i++)
	{
		cout<<"+ 1"<<endl;;
		cin>>op;

		if(mp.count(op)){
			cout<<"! "<<i<<endl;
			return ;
		}
		mp[op]=i;
	}
	for(int i=1,op;;i++)
	{
		cout<<"+ 1000"<<endl;
		cin>>op;


		if(mp.count(op))
		{
			cout<<"! "<<1000*i+999-mp[op]<<endl;
			break;
		}
	}
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
/*
1~1000
*/