/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int n,k;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=4*n;i++)
		p[i]=i;
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(op==1)
		{
			if(find(x+n)==find(y)||find(x)==find(y+n))
			{
				ans++;
				continue;
			}
			p[find(x)]=find(y);
			p[find(x+n)]=find(y+n);
			p[find(x+n+n)]=find(y+n+n);
		}
		else
		{
			// x chi y
			if(find(x)==find(y)||find(x+n+n)==find(y)||find(x)==find(y+n))
			{
				ans++;
				continue;
			}
			p[find(x+n)]=find(y);
			p[find(y+n+n)]=find(x);
			p[find(x+n+n)]=find(y+n);
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}
/*
100 6
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
x
x的同类 x吃的 吃x的 

1 -> 2
2 -> 3
3 -> 3 p
1 -> 3 p
3 -> 1 
*/