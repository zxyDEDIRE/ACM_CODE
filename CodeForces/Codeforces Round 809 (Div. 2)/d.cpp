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
int n,k;
struct node{
	int x,y,z;
	bool operator<(const node&a)const{
		return a.y>y;
	}
}p[maxn];
void solve()
{
	priority_queue<node>q;
	cin>>n;
	int ma,mi;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x;
		p[i].y=p[i].x;
		p[i].z=1;
		if(i==1)mi=p[i].x;
		mi=min(mi,p[i].x);
		ma=max(ma,p[i].x);
		q.push(p[i]);
	}
	while(1)
	{
		auto [x,y,z]=q.top();q.pop();
		ma=y;
		if(z==k)break;
		else
		{
			z++;
			y=x/z;
			q.push({x,y,z});
		}
	}
	cout<<ma-mi<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}