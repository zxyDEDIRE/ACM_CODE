#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define VNAME(value) (#value)
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
const int N=1111;
int p[N][N];
int s[N][N];
string str;
int n,m,k;
void init(int N,int M){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+p[i][j];
}
int get(int x1,int y1,int x2,int y2){
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void f(int&x,int L){
	if(x>L)x=L;
	if(x<=0)x=1;
}
void solve()
{
	cin>>n>>m>>k>>str;
	int _x=1,_y=1;
	int x_l=1,x_r=n,y_l=1,y_r=m;
	set<pii>s;
	s.insert({1,1});
	for(auto i:str)
	{
		if(i=='U')_x++;
		else if(i=='D')_x--;
		else if(i=='L')_y++;
		else _y--;
		s.insert({_x,_y});
		x_l=max(x_l,_x);
		x_r=min(x_r,_x+n-1);
		y_l=max(y_l,_y);
		y_r=min(y_r,_y+m-1);
	}

	if(x_l>x_r||y_l>y_r){
		if(k==0)cout<<n*m<<endl;
		else cout<<0<<endl;
		return ;
	}
	int num=(x_r-x_l+1)*(y_r-y_l+1);
	int fl_x=0,fl_y=0;
	for(auto [x,y]:s)
	{
		fl_x=max(fl_x,1-x);
		fl_y=max(fl_y,1-y);
	}
	int L=0,R=0;
	for(auto [x,y]:s)
	{
		L=max(L,x+fl_x);
		R=max(R,y+fl_y);
	}
	for(int i=1;i<=L;i++)
		for(int j=1;j<=R;j++)
			p[i][j]=0;
	for(auto [x,y]:s)
		p[x+fl_x][y+fl_y]=1;
	init(L,R);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int _x_l=x_l+fl_x-i;f(_x_l,L);
			int _x_r=x_r+fl_x-i;f(_x_r,L);
			int _y_l=y_l+fl_y-j;f(_y_l,R);
			int _y_r=y_r+fl_y-j;f(_y_r,R);
			int cnt=get(_x_l,_y_l,_x_r,_y_r);
			if(cnt+k==num)ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
3
4 5 3
ULDDRR
4 5 0
UUUUUUU
4 5 10
UUUUUUU
*/