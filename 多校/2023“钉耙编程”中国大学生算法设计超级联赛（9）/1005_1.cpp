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
vector<char>s;
int p[maxn];
int n,m,cnt;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void getline()
{
	char now=getchar();
	vector<char>v;
	while(now!='\n'){
		s.push_back(now);
		now=getchar();
	}
}
void solve()
{
	s.clear();
	getchar();
	getline();
	cnt=0;
	int num=0;
	int flag=0;
	for(int i=0;i<(int)s.size();i++)
	{
		char ch=s[i];
		if(ch<'0'||ch>'9'){
			if(flag)p[++cnt]=num;
			num=0;
			flag=0;
		}
		else
		{
			if(flag==0)
			{
				flag=1;
				num=ch-'0';
			}
			else
			{
				num=num*10+ch-'0';
			}
		}
	}
	cin>>n>>m;
	int now=0;
	// cout<<"[";
	putchar('[');
	for(int i=1;i<=n;i++)
	{
		// cout<<"[";
		putchar('[');
		for(int j=1;j<=m;j++)
		{
			// cout<<p[++now];
			write(p[++now]);
			if(j!=m)putchar(','),putchar(' ');
		}
		putchar(']');
		if(i!=n)putchar(','),putchar(' ');
	}
	putchar(']');
	puts("");
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;
	read(__);
	while(__--)
		solve();
	return 0;
}
/*
1
[3, 1, 4, 1, 5, 9, 2, 6]
*/