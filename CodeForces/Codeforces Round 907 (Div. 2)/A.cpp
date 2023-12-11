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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int l=1;
	for(int i=0;(1<<i)<=n;i++)
	{
		vector<int>v;
		for(int j=l;j<=(1<<i);j++)
			v.push_back(p[j]);
		for(int i=1;i<v.size();i++)
			if(v[i-1]>v[i]){
				cout<<"NO\n";
				return ;
			}
		l=(1<<i)+1;
	}
	vector<int>v;
	for(int i=l;i<=n;i++)
		v.push_back(p[i]);
	for(int i=1;i<v.size();i++)
		if(v[i-1]>v[i]){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
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