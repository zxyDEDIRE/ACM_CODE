/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int x,y,w;
}p[maxn];
int T[maxn];
int f[maxn];
vector<int>v;
int n,m,c;
int l=0,r,ans;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++)
		cin>>p[i].x>>p[i].y>>p[i].w;
	sort(p+1,p+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)
		f[i]=i;
	int num=n;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=p[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			num--;
			f[fa]=fb;
			v.push_back(w);
			r=max(r,w);
		}
		if(num==1)break;
	}
	int cnt=0;
	T[(int)(v.size())]=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		cnt++;
		T[i]=v[i]*cnt+T[i+1];
		if(T[i]>c){
			cout<<v[i]<<endl;
			return ;
		}
	}
	cout<<0<<endl;

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