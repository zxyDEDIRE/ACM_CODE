/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int x,y;
}p[maxn],a[maxn],b[maxn];
ll n,k;
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
ll A()
{
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=k;i++)
		a[i].x=1e9;
	sort(a+1,a+1+n,cmp1);

	int S=a[1].x*2;
	if(n==2)S/=2;

	sort(a+1,a+1+n,cmp2);

	int ma=0;
	for(int i=1;i<n;i++)
	{
		int mi;
		mi=min({a[i+1].x,a[i].x,S});
		ma=max(ma,mi);
	}
	return ma;
}
ll B()
{
	sort(b+1,b+1+n,cmp1);
	for(int i=1;i<k;i++)
		b[i].x=1e9;
	sort(b+1,b+1+n,cmp1);
	int ma=0;
	int S=2*b[1].x;
	sort(b+1,b+1+n,cmp2);
	for(int i=1;i<n;i++)
	{
		int mi;
		mi=min(S,max(b[i].x,b[i+1].x));
		//mi=min(mi,max(b[i].x,b[i+1].x));
		ma=max(ma,mi);
	}
	return ma;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x;
		p[i].y=i;
		a[i]=b[i]=p[i];
	}
	ll x=A();
	ll y=B();
	cout<<max(x,y)<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/