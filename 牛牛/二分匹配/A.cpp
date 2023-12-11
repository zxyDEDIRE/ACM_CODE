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
int ans[maxn];
int p[maxn];
int a[maxn];
int b[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void un(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)p[fa]=fb;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n*4;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		un(x,y+n*2);
		un(x+n*2,y);
	}
	ans[1]=1;
	for(int i=2;i<=n*2;i++)
	{
		if(find(i)!=find(i-1))
		{
			un(i,i-1+n*2);
			un(i+n*2,i-1);
			ans[i]=ans[i-1]==1?2:1;
		}
		else ans[i]=ans[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[a[i]]<<" "<<ans[b[i]]<<endl;
	}


}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}