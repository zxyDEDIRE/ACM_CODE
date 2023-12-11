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
struct node{
	int x,y;
}p[maxn];
map<string,int>pp;
int a[maxn];
int n;
void solve()
{
	cin>>n;
	vector<int>v;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str>>p[i].x,v.push_back(p[i].x),mp[p[i].x]++;
		pp[str]=i;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int tot=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		a[i]=tot+1;
		tot+=mp[v[i]];
	}
	for(int i=1;i<=n;i++)
	{
		p[i].y=lower_bound(v.begin(),v.end(),p[i].x)-v.begin();
		p[i].y=a[p[i].y];
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i].x<<" "<<p[i].y<<endl;
	int T=floor(n*0.3);
	int q;cin>>q;
	while(q--)
	{
		string str;cin>>str;
		if(p[pp[str]].y<=T)cout<<"YES\n";
		else cout<<"NO\n";
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