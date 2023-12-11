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
string s;
int n;
void solve()
{
	cin>>n>>s;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='H')cnt++;
		if(i+1<n&&s.substr(i,2)=="HE")cnt++;
		if(i+2<n&&s.substr(i,3)=="HEB")cnt++;
		if(i+3<n&&s.substr(i,4)=="HEBU")cnt++;
		if(i+4<n&&s.substr(i,5)=="HEBUT")cnt++;
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}