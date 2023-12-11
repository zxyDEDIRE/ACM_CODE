/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int x,y;
}p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y!=b.y)return a.y>b.y;
		return a.x<b.x;
	});
	m*=3;
	m=(m+1)/2;


	vector<node>v;

	for(int i=1;i<=n;i++)
	{
		if(v.size()==m)break;
		v.push_back(p[i]);
	}
	cout<<v[v.size()-1].y<<" "<<v.size()<<endl;
	for(auto i:v)
	{
		cout<<i.x<<" "<<i.y<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}