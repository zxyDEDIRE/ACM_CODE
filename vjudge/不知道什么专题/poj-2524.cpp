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
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	int tmp=1;
	while(cin>>n>>m)
	{
		if(n==0)return ;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb){
				p[fa]=fb;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(p[i]==i)
				cnt++;
		cout<<"Case "<<tmp++<<": ";
		cout<<cnt<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}