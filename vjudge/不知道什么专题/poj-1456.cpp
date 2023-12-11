/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<algorithm>
#include<iostream>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
typedef pair<int,int> pii;
pii p[maxn];
int f[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void un(int x,int y){
	int fa=find(x);
	int fb=find(y);
	f[fa]=fb;
}
bool cmp(pii a,pii b){
		if(a.first==b.first)return a.second<b.second;
		return a.first>b.first;
	}
void solve()
{
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
		ma=max(ma,p[i].second);
	}
	for(int i=1;i<=ma;i++)
		f[i]=i;
	sort(p+1,p+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		// auto [w,x]=p[i];
		int w=p[i].first;
		int x=p[i].second;
		int fa=find(x);
		if(fa){
			ans+=w;
			un(x,fa-1);
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>n){
		solve();
		// break;
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}