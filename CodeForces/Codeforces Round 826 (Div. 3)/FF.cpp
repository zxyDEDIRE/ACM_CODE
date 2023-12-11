/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
	int x,y,id;
}p[maxn];
vector<node>a,b;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,id;
		cin>>x>>y>>id;
		p[i]={x,y,id};
		a.push_back({x,y,id});
		b.push_back({x,y,id});
	}
	sort(a.begin(),a.end(),[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	});
	sort(b.begin(),b.end(),[&](node a,node b){
		if(a.y!=b.y)return a.y>b.y;
		return a.x>b.x;
	});
	for(int i=1;i<=n;i++)
	{
		auto [x,y,id]=p[i];
		int fla=upper_bound(a.begin(),a.end(),y)-a.begin();
		while(fla<n&&a[fla].id==id)fla++;
		int flb=upper_bound(b.begin(),b.end(),x,greater<int>())-b.begin();
		while(flb>=0&&b[flb].id==id)flb--;
		int l=INF,r=INF;
		if(fla<n)l=a[fla].x-y;
		if(flb>=0)r=x-b[flb].y;
		cout<<min(l,r)<<" ";
	}
	cout<<endl;
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