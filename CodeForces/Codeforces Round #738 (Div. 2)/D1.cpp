/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p1[maxn];
int p2[maxn];
int n,m1,m2;
int find1(int r){
	return p1[r]=p1[r]==r?p1[r]:find1(p1[r]);
}
int find2(int r){
	return p2[r]=p2[r]==r?p2[r]:find2(p2[r]);
}
void solve()
{
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)
		p1[i]=i,p2[i]=i;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find1(x);
		int fb=find1(y);
		p1[fa]=fb;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find2(x);
		int fb=find2(y);
		p2[fa]=fb;
	}
	vector<pii>v;
	for(int x=1;x<=n;x++)
	{
		for(int y=x+1;y<=n;y++)
		{
			int fa1=find1(x);
			int fb1=find1(y);
			int fa2=find2(x);
			int fb2=find2(y);
			if(fa1!=fb1&&fa2!=fb2)
			{
				v.push_back({x,y});
				p1[fa1]=fb1;
				p2[fa2]=fb2;
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto [x,y]:v)
		cout<<x<<" "<<y<<endl;
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
/*
点与点之间的关系
咋样去找到两个毫不相干的点
双指针
*/