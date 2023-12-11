#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int x,id,cnt;
}p[maxn];
int n,k;
void solve()
{
	cin>>n;
	int mi=INF;
	for(int i=1;i<=n;i++){
		cin>>p[i].x;
		p[i].id=i;
		p[i].cnt=0;
		mi=min(mi,p[i].x);
	}
	cin>>k;
	int cnt=k/mi;
	k%=mi;

	int flag;
	for(int i=n;i>=1;i--)
		if(p[i].x==mi){
			flag=i;
			break;
		}


	p[flag].cnt+=cnt;
	sort(p+flag+1,p+1+n,[&](node a,node b){
		return a.id<b.id;
	});

	// for(int i=1;i<=n;i++)
		// cout<<p[i].id<<" "<<p[i].cnt<<endl;
	int ma=flag;
	for(int i=flag+1;i<=n;i++)
	{
		if(p[i].id<ma)continue;
		if(mi==p[i].x && p[i].x==p[i-1].x)
		{
			p[i].cnt=p[i-1].cnt;
			p[i-1].cnt=0;
			ma=p[i].id;
		}
		else if(mi<p[i].x&&k>=(p[i].x-mi))
		{
			int now=k/(p[i].x-mi);
			now=min(now,p[i-1].cnt);
			p[i-1].cnt-=now;
			p[i].cnt+=now;
			k-=now*(p[i].x-mi);
			mi=p[i].x;
			ma=p[i].id;
		}
		// cout<<p[i].cnt<<" "<<p[i-1].cnt<<endl;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.id<b.id;
	});



	// for(int i=1;i<=n;i++)
	// 	cout<<p[i].cnt<<" ";cout<<endl;

	for(int i=n-1;i>=1;i--)
		p[i].cnt+=p[i+1].cnt;
	for(int i=1;i<=n;i++)
		cout<<p[i].cnt<<" ";cout<<endl;

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
1
3
10 13 12
37

3 3 1
*/