#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;

struct node{
	int l,r;
}t[maxn];

//先根遍历：
void dfs1(int x)
{
	printf("%d\n",x);
	if(t[x].l)
		dfs1(t[x].l);
	if(t[x].r)
		dfs1(t[x].r);
}

//中根遍历
void dfs2(int x)
{
	if(t[x].l)
		dfs2(t[x].l);

	printf("%d\n",x);

	if(t[x].r)
		dfs2(t[x].r);
}

//后根遍历
void dfs3(int x)
{
	if(t[x].l)
		dfs3(t[x].l);
	if(t[x].r)
		dfs3(t[x].r);
	printf("%d\n",x);
}


void solve()
{
	dfs1(1);
}
signed main(){
		solve();
	return 0;
}