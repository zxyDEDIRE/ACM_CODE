/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct node{
	int x_1,y_1,x_2,y_2;
};
int n,x,y;
node add(node a,int x,int y)
{
	node q=a;
	if(x==-1)q.x_1--;
	else q.x_2++;
	if(y==-1)q.y_1--;
	else q.y_2++;
	return q;
}
bool check(node t)
{
	if(t.x_1<1||t.y_1<1||t.x_2>n||t.y_2>n)return 0;
	return 1;
}
void dfs(node t)
{
	
	for(int i=4;i<8;i++)
	{
		node now=add(t,dx[i],dy[i]);
		if(!check(now))continue;
		int x,y,len_x,len_y;
		if(now.x_1==t.x_1)x=now.x_2,len_x=now.x_1-now.x_2;
		else x=now.x_1,len_x=now.x_2-now.x_1;
		if(now.y_1==t.y_1)y=now.y_2,len_y=now.y_1-now.y_2;
		else y=now.y_1,len_y=now.y_2-now.y_1;
		cout<<x<<" "<<y<<" "<<len_x<<" "<<len_y<<endl;
		dfs(now);
		break;
	}
}
void solve()
{
	cin>>n>>x>>y;
	cout<<"Yes"<<endl;
	cout<<n-1<<endl;
	dfs({x,y,x,y});
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