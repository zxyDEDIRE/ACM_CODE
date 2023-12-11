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
const int maxn=1e6;
vector<int>x[maxn],y[maxn];
int p[maxn];
int a[maxn];
int n,m;
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{

	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        if(solve());
    return 0;
}