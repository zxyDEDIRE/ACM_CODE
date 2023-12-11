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
string str;
// bool ok(char ch){
// 	if(str.find(ch)!=string::npos)
// 		return 1;
// 	return 0;
// }
void solve()
{
	cin>>str;
	map<char,int>mp;
	for(auto i:str)
		mp[i]++;
	string now="Baidu";
	for(auto i:now)
		if(mp[i]!=1||str.size()!=5){
			cout<<"No\n";
			return ;
		}
	cout<<"Yes\n";

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}