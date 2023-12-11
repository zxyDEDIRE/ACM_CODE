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
int n,k,t;
void solve()
{
	cin>>n>>k>>t;
	string now=string(t+1,'1');
	k-=t+1;
	if(k<0){
		cout<<-1<<endl;
		return ;
	}
	while(k)
	{
		now=now+"01";
		k--;
	}
	if(now.size()>n){
		cout<<-1<<endl;
		return ;
	}
	while(now.size()<n)
		now=now+"0";
	cout<<now<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
-> 地址 文件名
-> 处理成wsl地址
-> g++ 编译
*/