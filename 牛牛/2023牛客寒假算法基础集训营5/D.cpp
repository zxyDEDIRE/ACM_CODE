
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int first,second;
}a[maxn],b[maxn];
// pii a[maxn];
// pii b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;i++)
		cin>>b[i].first>>b[i].second;
	int x=1,y=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].first<=x)
			x=max(x,a[i].second+1);
		if(b[i].first<=y)
			y=max(y,b[i].second+1);
		// cout<<x<<" "<<y<<endl;
		if(x>y)
			cout<<"sa_win!"<<endl;
		else if(x<y)
			cout<<"ya_win!"<<endl;
		else cout<<"win_win!"<<endl;
		cout<<abs(x-y)<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}

