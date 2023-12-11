#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll x,y;
}p[maxn];
int a[maxn];
int q[maxn];
int vis[maxn];
int n,m,k,ma;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x;
		p[i].y=i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;});
	for(int i=1;i<=n;i++)
		a[i]=p[i].x;
	vector<int>v;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		ll x=p[i].x;
		int fl=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i)j++;
			if(p[j].x>x){
				fl=1;
				break;
			}
			x*=2;
			if(x>=p[n].x)break;
		}
		if(!fl)v.push_back(p[i].y);
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
/*
7
2 1 1 1 1 32 32

6
16 15 8 4 1 1
*/