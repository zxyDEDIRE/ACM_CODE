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
vector<int>v[maxn];
int num[maxn];
int f[maxn];
int p[maxn];
int a[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i,num[i]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int fa=find(i);
		int fb=find(a[i]);
		if(fa!=fb)
		{
			p[fb]=fa;
			
		}
	}
	for(int i=1;i<=n;i++)
	{

	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}