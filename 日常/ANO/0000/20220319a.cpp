#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int vis[2][maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++)cin>>p[i],num+=p[i];
	int a=0,b=0,len=1;p[n+1]=2;
	for(int i=2;i<=n+1;i++)
	{
		if(p[i]!=p[i-1]){
			if(p[i-1]==0)b=max(b,len);
			if(p[i-1]==1)a=max(a,len);
			len=1;
		}
		else len++;
	}
	int l=num+b;
	int r=num-a;
	cout<<l<<" "<<r<<endl;
	cout<<l-r+1<<endl;
}
signed main(){
	int __;
	__=1;
	while(__--)solve();
}
/*
整个数组加起来是num 
最长连续0是b 所以最大是num+b
最长连续1是a 所以最小是num-a 
答案是(num+b)-(num-a)+1  

5
1 1 0 1 1 

5
1 1 1 0 1
1 1 0 0 1
1 0 0 0 1
0 0 0 0 1
1 1 1 1 1
5

5
1 0 1 0 1
1 1 1 0 1
0 1 0 0 1
3

5
1 1 0 1 1
1 1 1 1 1 
0 1 0 1 1 
0 0 0 1 1 
4
*/
