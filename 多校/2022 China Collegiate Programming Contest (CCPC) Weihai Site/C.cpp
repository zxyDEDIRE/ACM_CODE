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
pii p[maxn];
pii a[10];
int n;
bool line(pii a,pii b,pii c)
{
	bool a1=a.first>b.first;
	bool a2=a.first>c.first;
	if(a1!=a2)return 0;
	bool b1=a.second>b.second;
	bool b2=a.second>c.second;
	if(b1!=b2)return 0;
	ll x1=a.first-b.first;
	ll x2=a.first-c.first;
	ll y1=a.second-b.second;
	ll y2=a.second-c.second;
	return x1*y2==x2*y1;
}
bool check(int x)
{
	a[5]=p[x];
	for(int i=1;i<=5;i++)
	{
		swap(a[1],a[i]);
		// cout<<"I "<<i<<" "<<a[1].first<<" "<<a[1].second<<endl;
		int flag=1;
		for(int j=2;j<=5;j++){
			if(flag)
			for(int k=j+1;k<=5;k++)
				if(line(a[1],a[j],a[k])){
					// cout<<j<<" "<<k<<endl;
					flag=0;break;
				}
		}
		if(flag)
		{
			cout<<"YES\n";
			for(int j=1;j<=5;j++)
				cout<<a[j].first<<" "<<a[j].second<<"\n";
			return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=1;i<=4;i++)a[i]=p[i];
	for(int j=5;j<=n;j++){
		if(check(j))
			return ;
	}
	cout<<"NO\n";
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