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
	int x,y,w,fl,id;
}a[maxn];
int ans[maxn];
int p[maxn];
int n,m,q,tot;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[++tot]={x,y,w,0,0};
	}
	for(int i=1;i<=q;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[++tot]={x,y,w,1,i};
	}
	sort(a+1,a+1+tot,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=tot;i++)
	{
		auto [x,y,W,fl,id]=a[i];
		int fa=find(x);
		int fb=find(y);
		if(fl)
		{
			if(fa!=fb)
				ans[id]=1;
		}
		else
		{
			if(fa!=fb)
				p[fa]=fb;
		}
	}
	for(int i=1;i<=q;i++)
		if(ans[i])
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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