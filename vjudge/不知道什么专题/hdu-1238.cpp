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
const int maxn=1e3+100;
string p[maxn];
int n;
bool check(string s)
{
	string t=s;
	reverse(t.begin(),t.end());
	for(int i=2;i<=n;i++)
	{
		if(p[i].find(s)==string::npos && p[i].find(t)==string::npos)
			return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
		getline(cin,p[i]);

	sort(p+1,p+1+n,[&](string a,string b){
		if(a.size()!=b.size())return a.size()<b.size();
		return a<b;
	});
	for(int len=p[1].size();len>=1;len--)
	{
		for(int i=0;i+len-1<p[1].size();i++)
		{
			string s="";
			for(int j=0;j<=len-1;j++)
				s=s+p[1][i+j];
			int T=check(s);
			// cout<<s<<" "<<T<<endl;
			if(T){
				cout<<len<<endl;
				return ;
			}
		}
	}
	cout<<0<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
2

wq
*/
