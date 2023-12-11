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
	ll c,w,f;
}p[maxn];
ll n,k;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		auto &[c,w,f]=p[i];
		cin>>c>>w>>f;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.f>b.f;
	});
	queue<node>q1,q2;
	for(int i=1;i<=n;i++)
	{
		if(p[i].w==1)q1.push(p[i]);
		else q2.push(p[i]);
	}
	ll ans=0;
	ll yu=0;
	while(!q1.size()||!q2.size())
	{
		if(!q2.size())
		{
			auto [c,w,f]=q1.front();q1.pop();
			if(c*w<=yu)
			{
				yu-=c*w;
			}
			else
			{
				ll now=c*w;
				now-=yu;
				ll _x = (now+k-1)/k;
				ans+=_x*f;
				yu=_x*k-now;
			}
		}
		else if(!q1.size())
		{
			auto [c,w,f]=q2.front();q1.pop();
			if(c*w<=yu)
			{
				yu-=c*w;
			}
			else
			{
				ll now=c*w;
				now-=yu;
				ll _k=k;
				if(k&1)_k--;
				ll _x = (now+_k-1)/_k;
				ans+=_x*f;
				yu=_x*(_k)-now;
			}
		}
		else
		{
			auto [c1,w1,f1]=q1.front();q1.pop();
			auto [c2,w2,f2]=q2.front();q2.pop();
			if(f1>=f2)
			{
				if(c1*w1<=yu)
				{
					yu-=c1*w1;
				}
				else
				{
					ll now=c1*w1;
					now-=yu;
					ll _x = (now+k-1)/k;
					ans+=_x*f1;
					yu=_x*k-now;
				}
			}
			else
			{
				if(c2*w2<=yu)
				{
					yu-=c2*w2;
					
				}
			}
		}
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
