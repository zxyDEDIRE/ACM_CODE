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
int n,x;
int p[4];
void solve()
{
	cin>>n>>x;
	p[x]=1;
	n%=6;
	for(int i=n;i>=1;i--)
	{
		if(i%2==1)swap(p[0],p[1]);
		else swap(p[2],p[1]);
	}
	for(int i=0;i<=2;i++)
		if(p[i]){
			cout<<i<<endl;
		}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
123

213
231
321
312
132
123
*/