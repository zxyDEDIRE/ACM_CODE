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
vector<char>a,b;
string s;
int n,k;
void solve()
{
	cin>>n>>k>>s;
	a.clear();
	b.clear();
	if((k%2)==0 && k<=n)
	{
		sort(s.begin(),s.end());
		cout<<s<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(i&1)b.push_back(s[i]);
			else a.push_back(s[i]);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int l=0,r=0;
		for(int i=0;i<n;i++)
		{
			if(i&1)cout<<b[r++];
			else cout<<a[l++];
		}
		cout<<endl;
	}
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
/*
nima
*/