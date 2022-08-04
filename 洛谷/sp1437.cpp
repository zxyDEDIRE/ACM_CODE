#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int a[maxn],b[maxn];
bitset<maxn>vis;
int n,fa,fb,ma=0;
void dfs(int x,int father)
{
	for(auto y:v[x]){
		if(y==father)continue;
		a[y]=a[x]+1;
		if(a[y]>ma)ma=a[y],fa=y;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		a[i]=0;
	ma=0;
	dfs(fa,-1);
	cout<<a[fa]<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}