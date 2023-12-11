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
	int id,x,ans;
}p[maxn];
int n;
void NO(){cout<<"NO\n";}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x>b.x;
	});
	int l=1,r=n,ano=0,w=n;
	for(int len=n;len>=1;len--)
	{
		int x=p[l].x-ano;
		int y=p[r].x-ano;
		if(y<0)return NO();
		if(x==len)
		{
			p[l].ans=w--;
			ano++;
			l++;
		}
		else if(y==0)
		{
			p[r].ans=-w;
			w--;
			r--;
		}
		else return NO();
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.id<b.id;
	});
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		cout<<p[i].ans<<" ";cout<<endl;
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
4
0 0 1 1
*/