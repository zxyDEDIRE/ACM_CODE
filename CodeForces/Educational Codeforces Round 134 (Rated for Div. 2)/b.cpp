/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1111;
bool ok[maxn][maxn];
bool vis[maxn][maxn];
int n,m,sx,sy,d;
int f(int x,int y)
{
	return abs(x-sx)+abs(y-sy);
}
void solve()
{
	cin>>n>>m>>sx>>sy>>d;
	int flag=1;
	for(int i=1;i<=n;i++)
		if(f(i,1)<=d){
			flag=0;
			break;
		}
	for(int i=1;i<=m;i++)
		if(f(n,i)<=d){
			flag=0;
			break;
		}
	if(flag){
		cout<<n+m-2<<endl;
		return ;
	}
	flag=1;
	for(int i=1;i<=m;i++)
		if(f(1,i)<=d){
			flag=0;
			break;
		}
	for(int i=1;i<=n;i++)
		if(f(i,m)<=d){
			flag=0;
			break;
		}
	if(flag){
		cout<<n+m-2<<endl;
		return ;
	}
	cout<<-1<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/