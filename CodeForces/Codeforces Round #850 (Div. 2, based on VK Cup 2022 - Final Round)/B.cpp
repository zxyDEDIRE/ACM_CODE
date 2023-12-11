/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
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
int a[maxn];
int b[maxn];
int n,h,w;
void solve()
{
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int l,r;
	//b[1]+r-h=a[1]-w
	//b[1]+l+h=a[1]+w
	l = a[1]+w-b[1]-h;
	r = a[1]-w-b[1]+h;
	for(int i=2;i<=n;i++)
	{
		// l = a[i]+w-b[i]-h;
		// r = a[i]-w-b[i]+h;
		// cout<<l<<" "<<r<<endl;
		l=max(l,a[i]+w-b[i]-h);
		r=min(r,a[i]-w-b[i]+h);
	}
	// cout<<l<<" "<<r<<endl;
	if(l>r)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}