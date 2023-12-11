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
	int l,r;
};
struct Node{
	int l,r,id;
}p[maxn];
vector<node>a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].l>>p[i].r>>p[i].id;
		a[p[i].id].push_back({p[i].l,p[i].r});
		b[p[i].id].push_back({p[i].l,p[i].r});
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i].begin(),a[i].end(),[&](node a,node b){
			if(a.l!=b.l)return a.l<b.l;
			return a.r<b.r;
		});
		sort(b[i].begin(),b[i].end(),[&](node a,node b){
			if(a.r!=b.r)return a.r<b.r;
			return a.l<b.l;
		});
	}
	for(int i=1;i<=n;i++)
	{
		  
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