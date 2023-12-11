#include<bits/stdc++.h>
// #include <sys/resource.h>
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
string s,t;
int n,m;
void solve()
{
	cin>>n>>m>>s>>t;
	vector<vector<int>>p(26);
	for(int i=n-1;i>=0;i--)
		p[s[i]-'a'].push_back(i);
	for(int i=0;i<m;i++)
	{
		int tmp=t[i]-'a';
		if(p[tmp].size()==0){
			cout<<"NO\n";
			return ;
		}
		for(int j=0;j<tmp;j++)
			while(p[j].size() &&p[j].back()<p[tmp].back())
				p[j].pop_back();
		p[tmp].pop_back();
	}
	cout<<"YES\n";

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// 	solve();
	return 0;
}
/*
1
5 5
sofia
afios
*/