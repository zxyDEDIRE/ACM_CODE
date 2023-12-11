#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define double long double
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
pdd p[maxn];
int n;
double f(double x,double y)
{
	double ans=0.0;
	for(int i=1;i<=n;i++)
		ans+=((x-1.0*p[i].first)*(x-1.0*p[i].first)+(y-1.0*p[i].second)*(y-1.0*p[i].second));

	cout<<ans<<endl;
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	// if(n==1){
	// 	cout<<
	// }
	double l1=-200000,r1=200000;
	while(r1-l1>1)
	{
		double m1=l1+(r1-l1)/3.0;
		double m2=r1-(r1-l1)/3.0;
		double ans_1=f(0,m1);
		double ans_2=f(0,m2);
		// cout<<m1<<" "<<ans_1<<endl;
		// cout<<m2<<" "<<ans_2<<endl;
		// cout<<endl;
		if(ans_2>=ans_1+1)r1=m2;
		else l1=m1;
	}
	double l2=-200000,r2=200000;
	while(r2-l2>1)
	{
		double m1=l2+(r2-l2)/3.0;
		double m2=r2-(r2-l2)/3.0;
		double ans_1=f(m1,l1);
		double ans_2=f(m2,l1);
		if(ans_2>=ans_1)r2=m2;
		else l2=m1;
	}
	map<double,vector<pii>>mp;
	double mi=-1;
	for(int i=floor(l2)-10;i<=ceil(r2)+10;i++)
		for(int j=floor(l1)-10;j<=ceil(r1)+10;j++){
			double now=f(i,j);
			mp[now].push_back({i,j});
			cout<<i<<" "<<j<<" "<<now<<endl;
			if(mi==-1)mi=now;
			mi=min(mi,now);
		}
	vector<pii>now = mp[mi];
	sort(now.begin(),now.end(),[&](pii a,pii b){
		return a.second<b.second;
	});
	cout<<l1<<" "<<r2<<endl;
	cout<<now[0].first<<" "<<now[0].second<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
2
100000 100000
0 0
*/