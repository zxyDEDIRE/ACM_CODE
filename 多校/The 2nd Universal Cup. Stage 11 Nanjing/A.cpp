#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int maxn=1e6+10;
const int mod=1e9+7;
const int N=1e3+100;

bitset<N>vis[N];
bitset<N>p[N];
struct node{
	int x1,y1,x2,y2,op,h,w,cnt;
	set<pii>s;
	void out(){
		cout<<"__________________________"<<endl;
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		for(int i=x1;i<=x2;i++)
		{
			for(int j=y1;j<=y2;j++)
				cout<<p[i][j];
			cout<<endl;
		}
		cout<<"==================="<<endl;
	}
};
vector<node>v;
int n,m;
void bfs(int x,int y)
{
	queue<pii>q;
	q.push({x,y});
	vis[x][y]=1;
	int x1=x,x2=x,y1=y,y2=y,cnt=0;
	set<pii>s;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		s.insert({x,y});
		x1=min(x1,x);y1=min(y1,y);
		x2=max(x2,x);y2=max(y2,y);
		cnt++;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(vis[xx][yy])continue;
			if(p[xx][yy]==0)continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	v.push_back({x1,y1,x2,y2,1,x2-x1+1,y2-y1+1,cnt,s});
	// v.push_back({x1,y1,x2,y2,1,x2-x1+1,y2-y1+1,cnt});
}
bool ok(node a,node b,int h,int w)
{
	auto &s1=a.s;
	auto &s2=b.s;

	// cout<<a.x1<<" "<<a.y1<<endl;
	// cout<<b.x1<<" "<<b.y1<<endl;

	int fl_x=(b.x1+h)-(a.x1);
	int fl_y=(b.y1+w)-(a.y1);
	// cout<<fl_x<<" "<<fl_y<<endl;

	for(auto &[x,y]:s1)
		if(!s2.count({x+fl_x,y+fl_y}))
			return 0;

	return 1;
}
int check(node a,node b)
{
	int h1=a.h,w1=a.w;
	int h2=b.h,w2=b.w;
	if(h1>h2&&w1<w2)return 0;
	if(h1<h2&&w1>w2)return 0;
	if(h1==h2&&w1==w2&&ok(a,b,0,0)&&ok(b,a,0,0))return 3;
	if(h1>=h2&&w1>=w2)
	{
		for(int i=0;i<=h1-h2;i++)
			for(int j=0;j<=w1-w2;j++)
				if(ok(b,a,i,j))
					return 2;
	}
	if(h1<=h2&&w1<=w2)
	{
		for(int i=0;i<=h2-h1;i++)
			for(int j=0;j<=w2-w1;j++)
				if(ok(a,b,i,j))
					return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	v.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			p[i][j]=(ch=='.');
			vis[i][j]=0;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])continue;
			if(p[i][j]==0)continue;
			bfs(i,j);
		}
	}
	int len=v.size();
	// cout<<"len:"<<len<<endl;
	// for(auto i:v)
	// 	i.out();
	// ok(v[0],v[2],0,0);
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<i;j++)
		{
			// if(v[i].op==0)break;
			// if(v[j].op==0)continue;
			int op=check(v[i],v[j]);
			// cout<<"check "<<i<<" "<<j<<" "<<op<<endl;
			if(op==1)v[i].op=0;
			if(op==2)v[j].op=0;
			if(op==3)v[i].op=v[j].op=0;
		}
	}
	// for(auto i:v)
	// 	cout<<i.op<<endl;
	int ans=0;
	for(auto i:v)
		if(i.op)
			ans+=i.cnt;
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4
2 5
.OO..
O..O.
1 3
O.O
1 3
.O.
2 3
OOO
OOO




2 5
.OO..
O..O.
1 3
O.O
1 3
.O.
2 3
OOO
OOO
4 6
.OOOOO
.OOO.O
..OO..
.OOOOO


4 6
.OOO..
.OOO..
OO..O.
OO..OO

3 8
........
........
........

3 8
...OO...
.OOOO..O
.O.OO.OO


*/