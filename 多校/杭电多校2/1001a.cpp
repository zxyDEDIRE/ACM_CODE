/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis,vi,on;
vector<int>v[maxn];
int n,q,cnt,fa,fb;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
}
inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
pii dfs(int x)
{
	if(on[x])return {0,0};
	on[x]=1;
	pii a,b;
	for(auto y:v[x]){
		b=dfs(y);
		a.first|=b.first;
		a.second|=b.second;
	}
	if(vis[x])a.first|=1;
	if(vi[x])a.second|=1;
	if(a.first&&a.second)cnt++;
	return a;

}
void solve()
{
	read(n);
	read(q);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=2;i<=n;i++)
	{
		int x;
		read(x);
		v[x].push_back(i);
	}
	while(q--)
	{
		vis.reset();
		vi.reset();
		on.reset();
		cnt=0;
		int a,b,c,x;
		read(a);read(b);read(c);
		for(int i=0;i<a;i++){
			read(x);
			vis[x]=1;
		}
		for(int i=0;i<b;i++){
			read(x);
			vi[x]=1;
		}
		for(int i=0;i<c;i++){
			read(x);
			fa=fb=0;
			dfs(x);
		}
		write(cnt);puts("");
	}
}
int main()
{	
	int __;read(__);
	while(__--)
		solve();
	return 0;
}