#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+100;
map<int,int>li;
int p[maxn];
set<int>s;
int n,m,ans;
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
void solve()
{
	read(n);
	read(m);
	ans=0;
	s.clear();
	li.clear();
	s.insert(INT_MAX);
	for(int i=1;i<=n;i++)
		read(p[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x);
		read(y);
		li[x]=y;
		if(!y)s.insert(x);
	}
	sort(p+1,p+1+n);
	for(int i=0,j=1;;i++)
	{
		int MAX=INT_MAX,cnt=0;
		if(li.count(i))MAX=li[i];
		while(j<n&&p[j]<i)j++;
		while(MAX!=cnt&&j<=n)
		{
			int y;
			if(s.size()>1)y=*s.upper_bound(i);
			else y=INT_MAX;
			if(p[j]<=y){
				cnt++;
				ans+=p[j++]-i;
			}
			else{
				i=y;
				break;
			}
		}
		while(*s.begin()<i)s.erase(*s.begin());
		if(j>n)break;
	}
	// cout<<ans<<endl;
	if(ans&1)puts("Pico");
	else puts("FuuFuu");
}
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int __;read(__);
	while(__--)
		solve();
}
/*
6 4
1 2 3 4 6 7
3 2
5 0
6 2
7 1

8 4
1 2 3 4 6 7 8 8
3 2
5 0
6 2
7 1


5 2
0 1 1 2 2
1 2
0 1


7 3
0 0 1 1 1 2 4
0 2
1 3
2 1
*/