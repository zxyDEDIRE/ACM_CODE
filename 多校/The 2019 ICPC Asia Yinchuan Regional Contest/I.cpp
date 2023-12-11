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
int n,m;
void mull(vector<ll>&v,int x)
{
	for(auto &y:v)
		y*=x;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]>=10)
		{
			if(i+1<v.size())v[i+1]+=v[i]/10;
			else v.push_back(v[i]/10);
			v[i]%=10;
		}
	}
}
void mull(vector<ll>&v,vector<ll>&u)
{

}
vector<ll>pow(int x,int y)
{
	vector<ll>v={1};
	for(int i=1;i<=y;i++)
		mull(v,x);
	return v;
}
void solve()
{
	// cin>>n>>m>>str;
	// reverse(str.begin(),str.end());
	// vector<int>v;
	// for(int i=0;i<str.size();i++)
	// {

	// }
	cout<<62<<" "<<62<<" ";
	cout<<string(120,'z');
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}