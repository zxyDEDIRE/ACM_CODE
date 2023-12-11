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
priority_queue<ll>q;
struct node{
	ll x,y;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y!=b.y)return a.y<b.y;
		return a.x<b.x;
	});
	ll t=0;
	for(int i=1;i<=n;i++)
	{
		if(t+p[i].x<=p[i].y)q.push(p[i].x),t+=p[i].x;
		else
		{
			if(p[i].x<q.top())
			{
				ll top=q.top();q.pop();
				if(t-top+p[i].x<=p[i].y)
				q.push(p[i].x),t=t-top+p[i].x;
			}
			
		}
	}
	cout<<q.size()<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}