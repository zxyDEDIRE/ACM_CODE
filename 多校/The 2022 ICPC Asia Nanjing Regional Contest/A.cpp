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
const int N=2111;
int p[N][N];
int s[N][N];
string str;
int n,m,k;
void init(int l1,int r1,int l2,int r2)
{
	// cout<<"L "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
	for(int i=l1;i<=l2;i++)
		for(int j=r1;j<=r2;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+p[i][j];
}
int get(int x1,int y1,int x2,int y2)
{
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
void solve()
{
	cin>>n>>m>>k>>str;
	int x=1,y=1,_x=1,_y=1;
	int w1=1,w2=m,h1=1,h2=n;

	int mi_x=1,mi_y=1;
	int ma_x=1,ma_y=1;
	for(auto i:str)
	{
		if(i=='U')x++,_x++;
		else if(i=='D')x--,_x--;
		else if(i=='L')y++,_y++;
		else y--,_y--;
		w1=max(w1,x);
		w2=min(w2,x+n-1);
		h1=max(h1,y);
		h2=min(h2,y+m-1);
		mi_x=min(mi_x,_x);
		mi_y=min(mi_y,_y);
		ma_x=max(ma_x,_x);
		ma_y=max(ma_y,_y);
		// cout<<_x<<" "<<_y<<endl;
	}
	int num=(w2-w1+1)*(h2-h1+1);
	if(w1>w2||h1>h2||num<k)
	{
		if(k==0)cout<<n*m<<endl;
		else cout<<0<<endl;
		return ;
	}
	// if(num==k){
	// 	cout<<n*m-k<<endl;
	// 	return ;
	// }

	// cout<<w1<<" "<<h1<<" "<<w2<<" "<<h2<<endl;
	// cout<<mi_x<<" "<<mi_y<<endl;
	int fl_x=max(0,1-mi_x);
	int fl_y=max(0,1-mi_y);
	// cout<<fl_x<<" "<<fl_y<<endl;

	int s_x=1+fl_x,s_y=1+fl_y;
	mi_x+=fl_x;
	ma_x+=fl_x;
	mi_y+=fl_y;
	ma_y+=fl_y;
	p[s_x][s_y]=1;
	memset(p,0,sizeof(p));
	for(auto i:str)
	{
		if(i=='U')s_x++;
		else if(i=='D')s_x--;
		else if(i=='L')s_y++;
		else s_y--;
		p[s_x][s_y]=1;
		// cout<<"S "<<s_x<<" "<<s_y<<endl;
	}
	// cout<<"MIMI "<<mi_x<<" "<<mi_y<<" "<<ma_x<<" "<<ma_y<<endl;
	// for(int i=1;i<=3;i++)
	// {
	// 	for(int j=1;j<=3;j++)
	// 		cout<<p[i][j]<<" ";cout<<endl;
	// }
	init(mi_x,mi_y,ma_x,ma_y);


	w1+=fl_x;
	w2+=fl_x;
	h1+=fl_y;
	h2+=fl_y;
	// cout<<w1<<" "<<h1<<" "<<w2<<" "<<h2<<endl;
	// cout<<get(w1,h1,w2,h2)<<endl;
	int now,cnt=0;
	// now=get(w1,h1,3,3);
	// cout<<"now "<<now<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x1=w1-i;
			int x2=w2-i;
			int y1=h1-j;
			int y2=h2-j; 
			// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
			x1=max(x1,mi_x);x1=min(x1,ma_x);
			x2=max(x2,mi_x);x2=min(x2,ma_x);
			y1=max(y1,mi_y);y1=min(y1,ma_y);
			y2=max(y2,mi_y);y2=min(y2,ma_y);
			// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
			now=get(x1,y1,x2,y2);
			// cout<<"now "<<now<<endl;
			if(now+k==num)cnt++;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
4 5 3
ULDDRR
2 5

2 4


1
2 2 1
ULDR

1
3 3 1
LLDD
*/