#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll x,y;
}p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i].x;
	for(int i=1;i<=k;i++)
		cin>>p[i].y;
	sort(p+1,p+1+k,[&](node a,node b){return a.x<b.x;});

	p[0].x=0;
	p[k+1].x=k+1;
	p[k+2].x=k+2;
	p[k+2].x=k+3;
	p[0].y=p[k+1].y=p[k+2].y=p[k+3].y=1e18;

	for(int i=1;i<=k;i++)
	{
		ll t=min(p[i-1].y+abs(p[i-1].x-p[i].x),p[i+1].y+abs(p[i+1].x-p[i].x));
	//	cout<<p[i].y<<" "<<p[i-1].y+abs(p[i-1].x-p[i].x)<<" "<<p[i+1].y+abs(p[i+1].x-p[i].x)<<endl;
		p[i].y=min(p[i].y,t);
	}

	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(l<k&&p[l].x<=l)l++;
		ll t=min({p[l-1].y+abs(p[l-1].x-i),p[l].y+abs(p[l].x-i),p[l+1].y+abs(p[l+1].x-i)});
		cout<<t<<" ";
	}
	cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
5

6 2
2 5
14 16

10 1
7
30

5 5
3 1 4 2 5
3 1 4 2 5

7 1
1
1000000000

6 3
6 1 3
5 5 5

*/