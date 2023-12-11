/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int n,m,x,y;
void solve()
{
	cin>>n>>m>>x>>y;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	p[m+1]=n+1;
	int k=y+2;
	int ans=0;
	int yu=x;
	for(int i=1;i<=m+1;i++)
	{
		int len=p[i]-p[i-1]-1;
		if(len<=yu)
		{
			if(y-len>x)
			{
				len=len-x-1;
				yu=x;
			}
			else if(y-len<=x)
			{
				yu=y-len;
			}
			continue;
		}
		if(len<yu)
		{
			ans++;
			if(len-1-yu>x)
			{
				len=len-1-yu;
				yu=x;
			}
			else
			{
				yu=len-1-yu;
			}
			continue;
		}
		ans+=len/k*2;
		len=len%k;
		if(len<=yu)
		{
			if(y-len>x)
			{
				len=len-x-1;
				yu=x;
			}
			else if(y-len<=x)
			{
				yu=y-len;
			}
		}
		else if(len==yu+1)
		{
			ans++;
			yu=x;
		}
		else if(len>yu+1)
		{
			ans++;
			if(y-(len-yu-1)>x)
			{
				len=y-(len-yu-1);
				len=len-x-1;
				yu=x;
			}
			else
			{
				yu=y-(len-yu-1);
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
17 2 3 3
6 12
6

10 1 3 3
1
3

14 2 5 7
6 9
0

9 0 3 3
3

10 0 2 2
4

10 1 3 3
9
3


20 0 4 6
4
*/
/*
10 1 2 2 
3
3

100 0 4 6
24

11 1 2 2
3
4

10 0 2 4
3

11 0 2 4
3

6 0 2 4
2

5 0 2 4
1

6 1 2 4
2
1
*/