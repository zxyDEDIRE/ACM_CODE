/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
int p[maxn];
int n,m,k,q;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n*2;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)p[fa]=fb,p[find(x+n)]=p[find(y+n)];
	}
	cin>>k;
	int ok=0;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa_1=find(x);
		int fa_2=find(x+n);
		int fb_1=find(y);
		int fb_2=find(y+n);
		if(fa_1==fb_1)ok=1;
		if(fa_2==fb_2)ok=1;
		if(fa_1!=fb_2)p[fa_1]=p[fb_2];
		if(fa_2!=fb_1)p[fa_2]=p[fb_1];
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa_1=find(x);
		int fa_2=find(x+n);
		int fb_1=find(y);
		int fb_2=find(y+n);
		if(ok||fa_2==fb_1||fa_1==fb_2)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
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