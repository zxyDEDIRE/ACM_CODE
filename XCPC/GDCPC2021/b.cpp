#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll x,y;
}p[maxn];
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
		return a.x>b.x;});
	vector<int>v;
	v.push_back(p[1].y);
	for(int i=2;i<=n;i++)
	{
		int cnt=max(q[i-1]-1,0);
		ll x=p[i].x;
		while(x<p[i-1].x)x*=2,cnt++;
		q[i]=cnt;
		int t=n-i;
	//	cout<<cnt<<" "<<t<<endl;
		if(cnt>t)break;
		else v.push_back(p[i].y);
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
/*
6
1 1 1 2 16 17

6
 1 1 1 1 17
16 2 1 1 1 1
0  3 4 4 4 4

17 2 1 1 1 1
0  4 5 

5
16 15 8 4 2 1
*/