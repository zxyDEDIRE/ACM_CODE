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
	string str;
	cin>>str;
	int len=str.size();
	set<int>s;
	for(int i=0;i<len/2;i++)
		s.insert(str[i]);
	if(s.size()==1){
		cout<<"-1\n";
		return ;
	}
	for(int i=0;i<len;i++)
	{
		if(str[i]!=str[i+1])
		{
			swap(str[i],str[i+1]);
			swap(str[len-i-1],str[len-i-2]);
			cout<<str<<"\n";

			return ;
		}
	}
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
aaa
aba
bbb
*/