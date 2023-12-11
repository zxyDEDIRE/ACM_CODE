/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
	int x,y,id;
}p[maxn];
bitset<maxn>vis;
ll n,h;
void solve()
{
	cin>>n>>h;
	int ma=0,ma_1,id=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;p[i].id=i;
		if(p[i].x>ma)ma=p[i].x,id=i,ma_1=p[i].y;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.y>b.y;
	});
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].y<ma)break;
		if(h<=0)break;
		h-=p[i].y;
		cnt++;
	}
	if(h)
	{
		cnt+=(h+ma-1)/ma;
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}