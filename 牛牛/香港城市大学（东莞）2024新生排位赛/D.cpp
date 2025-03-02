#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,op,len;
};
node t[maxn];
string str;
int n,m;
void solve()
{
	cin>>str;
	cin>>m;

	n=str.size();
	t[0].x=0;
	t[0].op=1;
	for(int i=1;i<=m;i++)
	{
		int x,op;
		cin>>x>>op;
		t[i].x=x;
		t[i].op=op;
	}
	for(int i=0;i<m;i++)
		t[i].len=t[i+1].x-t[i].x;
	t[m].len=n-t[m].x;

	// for(int i=0;i<=m;i++)
	// 	cout<<t[i].len<<endl;

	sort(t,t+m+1,[&](node a,node b){
		if(a.op!=b.op)return a.op<b.op;
		else if(a.op==1)
		{
			return a.x>b.x;
		}
		else
		{
			return a.x<b.x;
		}
	});
	// for(int i=0;i<=m;i++)
	// 	cout<<t[i].x<<" "<<t[i].op<<" "<<t[i].len<<endl;
	vector<pair<int,char>>p;
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=t[i].len;j++)
			p.push_back({t[i].x-1+j,'a'});
	}
	for(int i=0;i<n;i++)
		p[i].second=str[i];
	sort(p.begin(),p.end(),[&](pii a,pii b){
		return a.first<b.first;
	});
	for(auto [x,y]:p)
		cout<<y;
	cout<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

p[i+1]-p[i]

2
2
4
3
1
7 3 012 456 89
f e ngx iao yi
*/