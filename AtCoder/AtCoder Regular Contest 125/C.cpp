/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i],vis[p[i]]=1;
	deque<int>q;
	for(int i=1;i<=n;i++)
		if(!vis[i])q.push_back(i);
	for(int i=1;i<m;i++)
	{
		cout<<p[i]<<" ";
		if(!q.size())continue;
		int x=q.front();
		if(x<p[i])
		{
			cout<<x<<" ";
			q.pop_front();
		}
	}
	while(q.size())
	{
		int x=q.back();
		if(x>p[m]){
			cout<<x<<" ";
			q.pop_back();
		}
		else break;
	}
	cout<<p[m]<<" ";
	while(q.size()){
		cout<<q.back()<<" ";
		q.pop_back();
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}