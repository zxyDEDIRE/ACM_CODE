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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool dis[111][111][111];
struct node{
	int p[3],step;
};
int w[3];
int s,x,y;
void bfs()
{
	memset(dis,0,sizeof(dis));
	queue<node>q;
	q.push({w[0],0,0,0});
	dis[w[0]][0][0]=1;
	while(!q.empty())
	{
		node x=q.front();q.pop();
		if(x.p[0]==x.p[1]&&x.p[2]==0){
			cout<<x.step<<endl;
			return ;
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i==j)continue;
				//i->j;
				int mi=min(x.p[i],w[j]-x.p[j]);
				node now=x;
				now.p[i]-=mi;
				now.p[j]+=mi;
				if(!dis[now.p[0]][now.p[1]][now.p[2]])
				{
					dis[now.p[0]][now.p[1]][now.p[2]]=1;
					now.step=x.step+1;
					q.push({now});
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
void solve()
{
	if(w[1]<w[2])swap(w[1],w[2]);
	if(w[0]&1)cout<<"NO"<<endl;
	else bfs();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>w[0]>>w[1]>>w[2]&&w[0])
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4 1 3

8 5 3


*/