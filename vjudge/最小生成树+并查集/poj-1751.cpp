#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=562600;
struct node{
	int x,y;ll w;
}p[maxn];
pii a[maxn];
int f[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	int m;cin>>m;
	while(m--)
	{
		int x,y;cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)f[fa]=fb;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			p[++cnt].x=i;
			p[cnt].y=j;
			p[cnt].w=1ll*(a[i].first-a[j].first)*(a[i].first-a[j].first)+1ll*(a[i].second-a[j].second)*(a[i].second-a[j].second);
		}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			cout<<x<<" "<<y<<endl;
			f[fa]=fb;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int __;cin>>__;
    // while(__--)
        solve();
    return 0;
}