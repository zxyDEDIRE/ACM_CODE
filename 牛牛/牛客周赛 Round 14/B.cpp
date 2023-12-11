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
ll x,y;
void NO(){
	cout<<"-1\n";
}
void solve()
{
	cin>>x>>y;
	map<int,int>a,b;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			while(x%i==0)
				a[i]++,x/=i;
		}
	if(x!=1)a[x]++;
	for(int i=2;i*i<=y;i++)
		if(y%i==0){
			while(y%i==0)
				b[i]++,y/=i;
		}
	if(y!=1)b[y]++;
	int a2=a[2];
	int a3=a[3];
	int a5=a[5];
	int b2=b[2];
	int b3=b[3];
	int b5=b[5];
	a[2]=a[3]=a[5]=b[2]=b[3]=b[5]=0;
	int ans=a2-b2;
	if(a3-b3!=ans)return NO();
	if(ans<0)return NO();
	if(a5>b5)return NO();
	for(auto [x,y]:a)
		if(b[x]!=y)return NO();
	ans+=b5-a5;
	cout<<ans<<endl;
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
72
*/